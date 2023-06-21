#include<bits/stdc++.h>
using namespace std;
void solve(){
		int q;
		cin>>q;
		while(q--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		multiset<int> m1;
		int curr=0;
		int ans[n];
		for(int i=0;i<n;i++){
			if(a[i]>curr){
				m1.insert(a[i]);
			}
		
			 multiset<int>::iterator it = m1.upper_bound(curr);
			 if(it!=m1.begin()){
			 	--it;
			 	m1.erase(it);
			 }
			 if(m1.size()>curr){
				++curr;
			}
			ans[i]=curr;
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}//nlogn
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}