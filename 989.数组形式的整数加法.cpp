/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>b;
        while(k){
            b.push_back(k%10);
            k/=10;
        }
        reverse(b.begin(), b.end());
        return add(num,b);
    }
    vector<int> add(vector<int>&a,vector<int>&b){
        if(a.size()<b.size())return add(b,a);
        vector<int> c;
        int t=0;
        for(int i=a.size()-1,j=b.size()-1;i>=0;--i){
            t+=a[i];
            if(j>=0)t+=b[j--];
            c.push_back(t%10);
            t/=10;
        }
        if(t)c.push_back(t);
        reverse(c.begin(), c.end());
        return c;
    }
};
// @lc code=end

