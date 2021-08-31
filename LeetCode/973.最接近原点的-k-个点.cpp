/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSort(points, 0, points.size()-1, k);
        return {points.begin(),points.begin()+k};
    }
    void quickSort(vector<vector<int>>& q,int l,int r,int k){
        if(l>=r)return;
        int x=distance(q[l+r>>1]);
        int i=l-1,j=r+1;
        while(i<j){
            do ++i;while(distance(q[i])<x);
            do --j;while(distance(q[j])>x);
            if(i<j)swap(q[i],q[j]);
        }
        int sizeL=j-l+1;
        if(sizeL>=k)quickSort(q, l, j, k);
        else quickSort(q, j+1, r, k-sizeL);
    }
    int distance(vector<int> &point){
        return point[0]*point[0]+point[1]*point[1];
    }
};
// @lc code=end

