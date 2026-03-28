/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_set<char> window;
        for (int right = 0; right < n; right++){
            char c = s[right];
            while (window.count(c)){
                window.erase(s[left]);
                left++;
            }
            window.insert(c);
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

