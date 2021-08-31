/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 *
 * https://leetcode-cn.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (34.40%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 75.3K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
 * 
 * 你需要返回给定数组中的重要翻转对的数量。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,3,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,4,3,5,1]
 * 输出: 3
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度不会超过50000。
 * 输入数组中的所有数字都在32位整数的表示范围内。
 * 
 * 
 */

// @lc code=start
class Solution {
    int cnt=0;
    vector<int>temp;
public:
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size()); 
        mergeSort(nums, 0, nums.size()-1);
        return cnt;
    }
    void mergeSort(vector<int>&nums,int l,int r){
        if(l>=r)return;
        int mid=(l+r)>>1;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        int i=l,j=mid+1;
        int k=0;

        while(i<=mid&&j<=r){
            if(static_cast<long long>(nums[i])>static_cast<long long>(nums[j])*2){
                cnt+=mid-i+1;
                ++j;
            }else{
                ++i;
            }
        }
        
        i=l,j=mid+1;
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

