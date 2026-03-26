/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right){
            ans = std::max(ans, (right - left) * std::min(height[left], height[right]));
            height[left] < height[right] ? left++ : right--;
        }
        return ans;
    }
};
// @lc code=end

