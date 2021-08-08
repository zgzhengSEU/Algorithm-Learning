class Solution {
public:
    int numWays(int n) {
        // f(n)=f(n-1)+f(n-2)
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        int a=1,b=2,sum=0;
        int mod=1e9+7;
        for(int i=3;i<=n;++i){
            sum=(a+b)%mod;
            a=b%mod;
            b=sum%mod;
        }
        return sum;
    }
};