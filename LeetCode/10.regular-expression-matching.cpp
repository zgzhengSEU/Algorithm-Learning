/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (27.96%)
 * Likes:    6832
 * Dislikes: 950
 * Total Accepted:    597.1K
 * Total Submissions: 2.1M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 * 
 * 
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "aab", p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "mississippi", p = "mis*is*p*."
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int n, m;
    vector<vector<int>> f;
    bool isMatch(string s, string p) {
      n = s.size(), m = p.size();
      f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
      return dp(0, 0, s, p);
    }
    bool dp(int x, int y, string &s, string &p){
      if (f[x][y] != -1) return f[x][y];
      if (y == m) return f[x][y] = x == n;
      bool firstMatch = x < n && (s[x] == p[y] || p[y] == '.');
      if (y + 1 < m && p[y + 1] == '*') {
        f[x][y] = dp(x, y + 2, s, p) || firstMatch && dp(x + 1, y, s, p);
      } else {
        f[x][y] = firstMatch && dp(x + 1, y + 1, s, p);
      }
      return f[x][y];
    }
};
// @lc code=end

