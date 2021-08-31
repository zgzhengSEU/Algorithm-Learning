/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.48%)
 * Likes:    1165
 * Dislikes: 0
 * Total Accepted:    317.7K
 * Total Submissions: 748.1K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(bsearch_first(nums, target)==-1)return {-1,-1};
        return {bsearch_first(nums, target),bsearch_last(nums,target)};
    }
    int  bsearch_first(vector<int>&nums,int t){
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(nums[mid]>=t)r=mid;
            else l=mid+1;
        }
        if(nums.empty()||nums[l]!=t)return -1;
        return l;
    }
    int bsearch_last(vector<int>&nums,int t){
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=l+r+1>>1;
            if(nums[mid]<=t)l=mid;
            else r=mid-1;
        }
        return l;
    }
};
// @lc code=end

