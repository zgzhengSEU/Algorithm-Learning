/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto &it:bookings){
            ans[it[0]-1]+=it[2];
            if(it[1]<n)ans[it[1]]-=it[2];
        }
        for(int i=0;i<n;++i){
            if(i){
                ans[i]+=ans[i-1];
            }
        }
        return ans;
    }
};
// @lc code=end

