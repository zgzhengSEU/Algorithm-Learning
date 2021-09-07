/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.size();
        int res=0,cnt=0;
        for(int i=0;i<n;++i){
            if(s[i]=='R')++cnt;
            if(s[i]=='L')--cnt;
            if(cnt==0)++res;
        }
        return res;
    }
};
// @lc code=end

