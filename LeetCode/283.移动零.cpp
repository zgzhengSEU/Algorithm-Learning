/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.87%)
 * Likes:    1175
 * Dislikes: 0
 * Total Accepted:    445.5K
 * Total Submissions: 697.2K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx0=0,cur=0,n=nums.size();
        while(cur<n){
            while(idx0<n&&nums[idx0]!=0){
                ++idx0;
                ++cur;
            }
            while(cur<n&&nums[cur]==0)++cur;
            if(cur==n)break;
            swap(nums[idx0],nums[cur]);
        }
    }
};
// @lc code=end

