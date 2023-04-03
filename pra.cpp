#include<bits/stdc++.h>
using namespace std;
void solve(){
	int q;
	cin>>q;
	while(q--){
		vector<int> arr;
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(),arr.end());
		map<int,int> mp;
		for(int i=0;i<n;i++){
			mp[arr[i]]++;
		}
		int c=arr[n-1]+1;
		map<int,int> :: iterator it=mp.begin();
		while(it!=mp.end()){
			while((it->second > 1) and (k > 0)){
				vector<int> :: iterator it2 = lower_bound(arr.begin(),arr.end(),it->first);
				*it2 = c;c++;
				mp[it->first]--;k--;
			}
			++it;
		}
		mp.clear();
		int sum=0;
		for(int i=0;i<n;i++){
			mp[arr[i]]++;
		}
		it=mp.begin();
		while(it!=mp.end()){
			sum+=it->second;
		}
		int ans=0;
		it=mp.begin();
		while(it!=mp.end()){
			sum-= it->second;
			ans+=sum;
		}
		cout<<ans<<endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}
