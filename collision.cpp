#include<bits/stdc++.h>
using namespace std;
void solve(){
	int q;
	cin>>q;
	while(q>0){
		int n,m;
		cin>>n>>m;
		int xi,ui,yi,vi;
		map<int,int> x;
		map<int,int> y;
		for(int i=0;i<n;i++){
			cin>>xi>>ui;
			x[xi*ui]++;
		}
		for(int i=0;i<m;i++){
			cin>>yi>>vi;
			y[yi*vi]++;
		}
		auto it = x.begin();
		int count=0;
		while(it !=x.end()){
			auto it2 = y.find(it->first);
			if(it2!=y.end() and it2->second>0){
				count++;
				y[it->first]--;
			}
			++it;
		}
		cout<<count<<endl;
		q--;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}