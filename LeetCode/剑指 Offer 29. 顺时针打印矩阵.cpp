class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        if(!m)return ans;
        int n=matrix[0].size();
        int cbeg=0,lbeg=0,cend=m,lend=n;
        while(true){
            for(int i=cbeg,j=lbeg;j!=lend;++j)ans.push_back(matrix[i][j]);
            ++cbeg;if(cbeg==cend)break;
            for(int i=cbeg,j=lend-1;i!=cend;++i)ans.push_back(matrix[i][j]);
            --lend;if(lbeg==lend)break;
            for(int i=cend-1,j=lend-1;j>=lbeg;--j)ans.push_back(matrix[i][j]);
            --cend;if(cbeg==cend)break;
            for(int i=cend-1,j=lbeg;i>=cbeg;--i)ans.push_back(matrix[i][j]);
            ++lbeg;if(lbeg==lend)break;
        }
        return ans;
    }
};