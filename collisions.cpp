#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//solve();
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		map<int,int> xi;
		map<int,int> yi;
		for(int i=0;i<n;i++){
			int x,u;
			cin>>x>>u;
			xi[x*u]++;
		}
		for(int i=0;i<m;i++){
			int y,v;
			cin>>y>>v;
			yi[y*v]++;
		}
		int count=0;
		for(auto it:xi){
			auto it2=yi.find(it.first);
			if(it2!=yi.end()){
				count+=min(it.second,it2->second);
				yi.erase(it2);
			}
		}
		
		cout<<count<<endl;
	}
}
