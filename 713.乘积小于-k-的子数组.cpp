/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //left, right;
        // [left, right], [left + 1, right]...[right, right]
        // right - left + 1
        if(k <= 1)
            return 0;
        int ans = 0;
        int left = 0;
        int temp = 1;
        for (int right = 0; right < nums.size(); right++){
            temp *= nums[right];
            while (temp >= k){
                temp /= nums[left];
                left++;
            }
            ans += right-left + 1;
        }
        return ans;
    }
};
// @lc code=end

