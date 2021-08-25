/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(auto it:nums)++cnt[it];
        vector<pair<int,int>> q;
        for(auto it:cnt)q.push_back({it.second,it.first});
        quicksort(q, 0, q.size()-1, k);
        vector<int> ans;
        for(int i=0;i<k;++i)ans.push_back(q[i].second);
        return ans;
    }
    void quicksort(vector<pair<int,int>>& q,int l,int r,int k){
        if(l>=r)return;
        int x=q[l+r>>1].first;
        int i=l-1,j=r+1;
        while(i<j){
            do ++i;while(q[i].first>x);
            do --j;while(q[j].first<x);
            if(i<j)swap(q[i],q[j]);
        }
        int sizeL=j-l+1;
        if(sizeL>=k) quicksort(q, l, j, k);
        else quicksort(q, j+1, r, k-sizeL);
    }
};
// @lc code=end

