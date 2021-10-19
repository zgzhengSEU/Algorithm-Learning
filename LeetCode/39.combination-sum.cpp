/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (62.28%)
 * Likes:    7692
 * Dislikes: 184
 * Total Accepted:    856.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 *
 *
 * Example 5:
 *
 *
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> res;
  vector<int> cur;
  int n;
  vector<vector<int>> combinationSum(vector<int>& c, int target) {
    n = c.size();
    vector<int> cur;
    dfs(0, c, target);
    return res;
  }
  void dfs(int u, vector<int>& c, int t) {
    if (t == 0) {
      res.push_back(cur);
      return;
    }
    if (u == n) return;
    for (int i = 0; i * c[u] <= t; ++i) {
      dfs(u + 1, c, t - i * c[u]);
      cur.push_back(c[u]);  //对下一次迭代不影响，故不需要恢复现场
    }
    //这一层递归结束返回时，需要恢复现场，不然会对上一层遍历的下一次迭代中的的递归有影响
    for (int i = 0; i * c[u] <= t; ++i) {
      cur.pop_back();
    }
  }
};
// @lc code=end
