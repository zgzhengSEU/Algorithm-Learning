/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return nums;
    }
    void mergeSort(vector<int>&nums,int l,int r,vector<int>&temp){
        if(l>=r)return;
        int mid=l+r>>1;
        mergeSort(nums, l, mid,temp);
        mergeSort(nums, mid+1, r,temp);
        int i=l,j=mid+1;
        int k=0;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j])temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=mid)temp[k++]=nums[i++];
        while(j<=r)temp[k++]=nums[j++];
        for(int i=0;i+l<=r;++i)nums[i+l]=temp[i];
    }
};
// @lc code=end

