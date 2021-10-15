/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (35.70%)
 * Likes:    3041
 * Dislikes: 2866
 * Total Accepted:    1M
 * Total Submissions: 2.9M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 *
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 *
 *
 * Constraints:
 *
 *
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack and needle consist of only lower-case English characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int strStr(string s, string p) {
    if (p.empty()) return 0;
    int n = s.size(), m = p.size();
    s = ' ' + s, p = ' ' + p;
    vector<int> ne(m + 1);
    for (int i = 2, j = 0; i <= m; ++i) {
      while (j && p[i] != p[j + 1]) j = ne[j];
      if (p[i] == p[j + 1]) ++j;
      ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; ++i) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) ++j;
      if (j == m) return i - j;
    }
    return -1;
  }
};
// @lc code=end
