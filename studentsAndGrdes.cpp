// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
using lli = long long;
void solve(){
	int q;
	cin>>q;
	while(q>0){
		int n,m;
		cin>>n>>m;
		map<lli,lli> map;
		for(int i=0;i<n;i++){
			lli a;
			cin>>a;
			map[a]++;
		}
		for(int j=0;j<m;j++){
			lli b;
			cin>>b;
			auto it = map.find(b);
			if(it!=map.end()){cout<<"YES"<<endl;}
			else{cout<<"NO"<<endl;}
			map[b]++;
		}
		q--;
	}

}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}