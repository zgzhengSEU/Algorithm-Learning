/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (51.47%)
 * Likes:    3748
 * Dislikes: 104
 * Total Accepted:    465.4K
 * Total Submissions: 903.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        dfs(0, c, target);
        return res;
    }
    void dfs(int u, vector<int>& c, int t) {
        if (t == 0) {
            res.push_back(cur);
            return;
        }
        if (u == c.size()) return;
        int cnt = 1;
        while (u + 1 < c.size() && c[u + 1] == c[u]) ++u, ++cnt;
        int i = 0;
        for (; i * c[u] <= t && i <= cnt; ++i) {
            dfs(u + 1, c, t - i * c[u]);
            cur.push_back(c[u]);//对下一次迭代不影响，故不需要恢复现场
        }
        //这一层递归结束返回时，需要恢复现场，不然会对上一层遍历的下一次迭代中的的递归有影响
        for (int i = 0; i * c[u] <= t && i <= cnt; ++i) {
            cur.pop_back();
        }
    }
};
// @lc code=end

