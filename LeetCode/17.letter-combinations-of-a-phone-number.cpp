/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.78%)
 * Likes:    7622
 * Dislikes: 589
 * Total Accepted:    974K
 * Total Submissions: 1.9M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> hash = {
        {'0', ""}, {'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        dfs(0, digits, "");
        return ans;
    }
    void dfs(int u, string &digits, string path) {
        if (u == digits.size()) {
            ans.push_back(path);
            return ;
        }
        for (auto c : hash[digits[u]]) {
            dfs(u + 1, digits, path + c);
        }
    }
};
// @lc code=end

