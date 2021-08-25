/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }

    int quickSelect(vector<int> &nums,int l,int r,int k){
        if(l>=r) return nums[l];
        int x=nums[l+r>>1];
        int i=l-1,j=r+1;
        while(i<j){
            while(nums[++i]>x);
            while(nums[--j]<x);
            if(i<j)swap(nums[i], nums[j]);
        }
        int sizeL=j-l+1;
        if(sizeL>=k) return quickSelect(nums, l, j, k);
        return quickSelect(nums, j+1, r, k-sizeL);
    }
};
// @lc code=end

