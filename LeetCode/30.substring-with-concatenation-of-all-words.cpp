/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (27.26%)
 * Likes:    1531
 * Dislikes: 1658
 * Total Accepted:    226.6K
 * Total Submissions: 830.8K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of
 * each word in words exactly once, in any order, and without any intervening
 * characters.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lower-case English letters.
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    unordered_map<string, int> total;
    for (auto& word : words) ++total[word];
    int w = words[0].size(), n = words.size();
    for (int i = 0; i < w; ++i) {
      unordered_map<string, int> wd;
      int cnt = 0;
      for (int j = i; j + w <= s.size(); j += w) {
        if (j - i >= n * w) {
          auto t = s.substr(j - n * w, w);
          if (wd[t] <= total[t]) --cnt;
          --wd[t];
        }
        auto word = s.substr(j, w);
        if (++wd[word] <= total[word]) ++cnt;
        if (cnt == n) res.push_back(j - (n - 1) * w);
      }
    }
    return res;
  }
};
// @lc code=end
