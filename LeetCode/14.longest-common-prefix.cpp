/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (37.92%)
 * Likes:    5658
 * Dislikes: 2530
 * Total Accepted:    1.2M
 * Total Submissions: 3.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0;; ++i) {
            if (i >= strs[0].size()) return strs[0];
            for (auto &str : strs) {
              if (i >= str.size() || str[i] != strs[0][i]) return strs[0].substr(0,i);
            }
        }
    }
};
// @lc code=end

