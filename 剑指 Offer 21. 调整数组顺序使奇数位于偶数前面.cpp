class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n=nums.size(),slow=0,fast=0;
        while(fast!=n){
            if(nums[fast]%2==0){
                ++fast; 
                continue;
            }
            swap(nums[slow++],nums[fast++]);
        }
        return nums;
    }
};