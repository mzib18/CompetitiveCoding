#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		priority_queue <int, vector<int>, greater<int>> pq;vector<int> ans;
		int size=(int)pq.size();
		for(int &i: arr){
			if(size<i){
				size++;
			while(!pq.empty() and pq.top()<size)pq.pop();
			pq.push(i);
			size=pq.size();	
			}
			ans.push_back(size);
		}
		for(int &i : ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
