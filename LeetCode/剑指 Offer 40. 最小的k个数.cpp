class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size()-1, k);
        arr.resize(k);
        return arr;
    }
    void quickSort(vector<int> &arr,int l,int r,int k){
        if(l>=r) return;
        int x=arr[l+r>>1];
        int i=l-1,j=r+1;
        while(i<j){
            do ++i;while(arr[i]<x);
            do --j;while(arr[j]>x);
            if(i<j)swap(arr[i],arr[j]);
        }
        int sizeL=j-l+1;
        if(sizeL>=k)quickSort(arr, l, j, k);
        else quickSort(arr, j+1, r, k-sizeL);
    }
};