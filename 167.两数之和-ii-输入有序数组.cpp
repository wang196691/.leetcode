/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() -1;
        while (left < right){
            int temp = numbers[left] + numbers[right];
            if ( temp < target)
                left++;
            else if (temp > target)
                right--;
            else 
                return {left + 1, right + 1};
        }
        return {};
    }
};
// @lc code=end

