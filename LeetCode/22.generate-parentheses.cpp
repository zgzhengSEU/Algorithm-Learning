/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (67.70%)
 * Likes:    10075
 * Dislikes: 403
 * Total Accepted:    875.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    int n;
    vector<string> generateParenthesis(int _n) {  
        n = _n;
        dfs(0, 0, "");
        return ans;
    }
    void dfs(int lc, int rc, string s) {
        if (lc == n && rc == n) ans.push_back(s);
        else {
            if (lc < n) dfs(lc + 1, rc, s + '(');
            if (rc < n && lc > rc) dfs(lc, rc + 1, s + ')');
        }
    }
};
// @lc code=end

