#include<bits/stdc++.h>
using namespace std;
// 1011
int binary_exponentiation(int a,int b,int mod){
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

signed main(){
	int a,b;
    cin>>a>>b;

    cout<<binary_exponentiation(a,b,1e9+7)<<endl;
}
