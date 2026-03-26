/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // std::sort(nums.begin(), nums.end());// 默认升序排序
        std::ranges::sort(nums);
        // std::sort(nums.begin(), nums.end(), std::greater<int>()) //降序排序
        // std::sort(nums.begin(), nums.end(), [](int a, int b){
        //     return a < b; // 升序排序
        // });
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++){
            int x = nums[i];
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (x + nums[i + 1]+ nums[i +2] > 0) break;  //剪枝1
            if (x + nums[n - 1] + nums[n - 2] < 0) continue;  //剪枝2

            int j = i +1, k = n -1;
            
            while (j < k){
                int temp = x + nums[j] + nums[k];
                if (temp < 0){
                    j++;
                }else if (temp > 0){
                    k--;
                }else{
                    ans.push_back({x, nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

