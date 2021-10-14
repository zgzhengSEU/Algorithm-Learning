/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.56%)
 * Likes:    13489
 * Dislikes: 1303
 * Total Accepted:    1.5M
 * Total Submissions: 5.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (i && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1, k = nums.size() - 1; j < k; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) --k;
        if (nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
      }
    }
    return res;
  }
};
// @lc code=end

