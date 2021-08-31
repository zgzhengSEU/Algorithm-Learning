/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(),N=n+10;
        int q[N],t=-1,h=0;
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(h<=t&&q[h]<i-k+1)++h;
            while(h<=t&&nums[i]>=nums[q[t]])--t;
            q[++t]=i;
            if(i>=k-1)ans.push_back(nums[q[h]]);
        }
        return ans;
    }
};
// @lc code=end

