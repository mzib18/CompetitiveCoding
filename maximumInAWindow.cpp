#include<bits/stdc++.h>
using namespace std;
void solve(){
	int q;
	cin>>q;
	while(q>0){
		int n,k;
		cin>>n>>k;
		int nums[n];
		vector<int> ans;
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
		multiset<int> mt;
		for(int i=0;i<k;i++){
			mt.insert(nums[i]);
		}
		int j=0;
		int z=k;
		while(j<(n-k+1)){
			ans.push_back(*mt.rbegin());
			mt.erase(mt.lower_bound(nums[j]));
			if(z<n){mt.insert(nums[z]);z++;}
			j++;
		}
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		q--;
		cout<<endl;
	}
}//O(NLOGK)
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}