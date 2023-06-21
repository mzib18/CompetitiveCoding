#include<bits/stdc++.h>
using namespace std;
void solve(){
	int q;
	cin>>q;
	while(q>0){
		int n,m;
		cin>>n>>m;
		vector<int> a;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;a.push_back(x);
		}
		sort(a.begin(),a.end());
		int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > m) break;
            cnt++;
            m -= a[i];
        }
		q--;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}