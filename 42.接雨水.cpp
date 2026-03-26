/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // int trap(vector<int>& height) {
    //     //时间复杂度O(n)
    //     //空间复杂度O(n)
    //     int n = height.size();
    //     vector<int> pre_max(n);  // 前缀最大值
    //     pre_max[0] = height[0];
    //     for (int i = 1; i< n; i++){
    //         pre_max[i] = std::max(pre_max[i - 1], height[i]);
    //     }
    //     for (int val : pre_max){
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    //     vector<int> suf_max(n);  // 后缀最大值
    //     suf_max[n - 1] = height[n - 1];
    //     for (int i = n - 2; i >= 0; i --){
    //         suf_max[i] = std::max(suf_max[i + 1], height[i]);
    //     }
    //     for (int val : suf_max){
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    //     int ans = 0;
    //     for (int i = 0; i < n; i++){
    //         ans += std::min(pre_max[i], suf_max[i]) - height[i];
    //     }
    //     return ans;
    // }
    int trap(vector<int>& height) {
        // 时间复杂度O(n)
        // 空间复杂度O(1)
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int pre_max = 0, suf_max = 0;
        while (left < right){
            pre_max = std::max(pre_max, height[left]);
            suf_max = std::max(suf_max, height[right]);
            if (pre_max < suf_max){
                ans += pre_max - height[left];
                left++;
            }else{
                ans += suf_max - height[right];
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

