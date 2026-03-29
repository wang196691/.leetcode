#include <atomic>
#include <condition_variable>
#include <mutex>
#include <vector>

template <typename T>
class RingBuffer {
private:
    std::vector<T> buffer_;
    size_t capacity_;

    mutable std::mutex mutex_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;

    size_t head_;   // 读指针
    size_t tail_;   // 写指针
    size_t count_;  // 当前元素数量

public:
    explicit RingBuffer(size_t capacity)
        : buffer_(capacity),
          capacity_(capacity),
          head_(0),
          tail_(0),
          count_(0) {}
    // buffer_ = std::vector<T>(capacity);
    // capacity_ = capacity;
    // head_ = 0;
    // tail_ = 0;
    // count_ = 0;

    // 写入数据
    bool push(const T& item) {
        std::lock_guard<std::mutex> lock(mutex_);

        if (isFull()) {
            return false;
        }

        buffer_[tail_] = item;
        tail_ = (tail_ + 1) % capacity_;
        ++count_;

        not_empty_.notify_one();
        return true;
    }

    // 写入数据（移动语义）
    bool push(T&& item) {
        std::lock_guard<std::mutex> lock(mutex_);

        if (isFull()) {
            return false;
        }

        buffer_[tail_] = std::move(item);
        tail_ = (tail_ + 1) % capacity_;
        ++count_;

        not_empty_.notify_one();
        return true;
    }

    // 读取数据
    bool pop(T& item) {
        std::unique_lock<std::mutex> lock(mutex_);

        not_empty_.wait(lock, [this]() { return !isEmpty(); });

        if (isEmpty()) {
            return false;
        }

        item = std::move(buffer_[head_]);
        head_ = (head_ + 1) % capacity_;
        --count_;

        not_full_.notify_one();
        return true;
    }

    // 非阻塞读取
    bool tryPop(T& item) {
        std::lock_guard<std::mutex> lock(mutex_);

        if (isEmpty()) {
            return false;
        }

        item = std::move(buffer_[head_]);
        head_ = (head_ + 1) % capacity_;
        --count_;

        not_full_.notify_one();
        return true;
    }

    // 获取缓冲区大小
    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return count_;
    }

    // 获取容量
    size_t capacity() const { return capacity_; }

    // 是否为空
    bool isEmpty() const { return count_ == 0; }

    // 是否已满
    bool isFull() const { return count_ == capacity_; }

    // 清空缓冲区
    void clear() {
        std::lock_guard<std::mutex> lock(mutex_);
        head_ = 0;
        tail_ = 0;
        count_ = 0;
    }
};