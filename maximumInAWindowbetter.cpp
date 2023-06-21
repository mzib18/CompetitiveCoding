#include<bits/stdc++.h>
using namespace std;
void solve(){
	int q;
	cin>>q;
	while(q>0){
		int n,k;
		cin>>n>>k;
		deque<int> dq;
		vector<int> ans;
		int nums[n];
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
		for(int i=0;i<n;i++){
			if(!dq.empty() and dq.front()==i-k)dq.pop_front();//for out of bounds
			while(!dq.empty() and nums[dq.back()]<nums[i])
				dq.pop_back();
			dq.push_back(i);
			if(i>=k-1)
				ans.push_back(nums[dq.front()]);
		}
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		q--;
	}//O(n)
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}