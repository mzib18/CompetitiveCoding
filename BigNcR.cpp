#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int inverse(int a,int b,int m){//O(log p)
    int ans=1;
    while(b) {
        if (b % 2 == 1) {
            ans = 1ll*ans*a %m;
        }
        a = 1ll*a*a %m;
        b/=2;
    }
    return ans;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	int fact[100001];fact[0]=1;
	for(int i=1;i<100001;i++){
		fact[i] = (1ll*i%mod * fact[i-1]%mod)%mod;
        //cout<<i<<" "<<fact[i]<<endl;
	}
	while(t--){
		int n,r;
		cin>>n>>r;
		int a = fact[n];
		int b= fact[n-r];
		int c= fact[r];
		int binverse,cinverse;
		binverse = inverse(b,mod-2,mod);
        //cout<<"binverse"<<binverse<<endl;
		cinverse = inverse(c,mod-2,mod);
        //cout<<"cinverse"<<cinverse<<endl;
        //int r = (binverse%mod * cinverse%mod)
		int ans = (1ll*a%mod * binverse%mod * cinverse%mod)% mod;
		cout<<ans<<endl;
	}
}
