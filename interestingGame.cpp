#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1,pair<int,int> p2){
	if(p1.first>p2.first)return true;
	else if (p1.first<p2.first)return false;
	else 
	if(p1.second<p2.second)return true;
	else if(p1.second>p2.second)return false;
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];int b[n];
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		pair<int,int> p[n];
		for(int i=0;i<n;i++){
			p[i].first=a[i]+b[i];
			p[i].second=i;
		}
		sort(p,p+n,comp);
        int alice=0;int bob=0;
		for(int i=0,j=0;i<n;i++,j^=1){
			if(!j)alice+=a[p[i].second];
			else bob+=b[p[i].second];
		}
		if(alice>bob)cout<<"Alice"<<endl;
		else if(alice<bob)cout<<"Bob"<<endl;
		else cout<<"Tie"<<endl;
	}
}
