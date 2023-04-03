#include<bits/stdc++.h>
using namespace std;

int inverse(int a,int b,int mod){//O(log p)
    int ans=1;
    while(b) {
        if (b % 2 == 1) {
            ans = 1ll*ans*a %mod;
        }
        a = 1ll*a*a %mod;
        b/=2;
    }
    return ans;
}
// a^-1 mod p = a^(p-2) mod p
signed main(){
    int a;
    cin>>a;
    cout<<inverse(a,1e9+7-2,1e9+7)<<endl;
}