/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        vector<int> results;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                results.push_back(pre[i][j]);
            }
        }

        return quickSort(results,0,m*n-1,k);
    }
    int quickSort(vector<int>& value,int l,int r,int k){
        if(l>=r)return value[l];
        int x=value[l+r>>1];
        int i=l-1,j=r+1;
        while(i<j){
            while(value[++i]>x);
            while(value[--j]<x);
            if(i<j)swap(value[i],value[j]);
        }
        int sizeL=j-l+1;
        if(sizeL>=k)return quickSort(value, l, j, k);
        else return quickSort(value, j+1, r, k-sizeL);
    }
};
// @lc code=end

