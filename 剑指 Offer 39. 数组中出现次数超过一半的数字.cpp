class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vot=0,temp;
        for(auto it:nums){
            if(!vot)temp=it;
            if(it!=temp)--vot;
            else ++vot;
        }
        return temp;
    }
};