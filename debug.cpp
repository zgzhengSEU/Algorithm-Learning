#include <iostream>
using namespace std;

int main(){
    float n;
    cin>>n;
    bool negative=true;
    if(n<0)n=-n;
    else negative=true;
    float l=0,r=10000;
    while(l-r>1e-8){
        float mid=(l+r)/2;
        if(mid*mid*mid<=n)l=mid;
        else r=mid;
    }
    if(negative)cout<<-l;
    else cout<<l;
    return 0;
}