/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; right++){
            sum += nums[right];
            // while (sum - nums[left] >= target){
            //     sum -= nums[left];
            //     left++;
            // }
            // if (sum >= target){
            //     ans = std::min(ans, right - left + 1); 
            //     //是否要+1, 可以假设right == left 时的情况
            // }
            //单调性
            while (sum >= target){
                ans = std::min(ans, right - left + 1); 
                sum -= nums[left];
                left++;
            }
        }
        return ans <= n ? ans : 0;
    }
};
// @lc code=end

