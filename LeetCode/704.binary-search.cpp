/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(nums[mid]>=target)r=mid;
            else l=mid+1;
        }
        return nums[l]==target?l:-1;
    }
};
// @lc code=end

