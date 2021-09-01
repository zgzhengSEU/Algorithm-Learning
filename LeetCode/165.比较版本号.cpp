/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int i=0,j=0;
        while(i<n1||j<n2){
            int x=0,y=0;
            while(i<n1&&isdigit(version1[i])){
                x=x*10+version1[i++]-'0';
            }
            while(j<n2&&isdigit(version2[j])){
                y=y*10+version2[j++]-'0';
            }
            if(x==y){
                ++i;
                ++j;
            }else{
                return x>y?1:-1;
            }
        }
        return 0;
    }
};
// @lc code=end

