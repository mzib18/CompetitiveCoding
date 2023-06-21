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
		 stack<pair<int,int>>st;
       int n=arr.size();
       vector<int>left(n);
       for(int i=0;i<n;i++){
           int count=1;
          while(!st.empty()&&st.top().first>=arr[i]){
             count+=st.top().second;
             st.pop();
          }
          st.push({arr[i],count});
          left[i]=count;
       }
       while(!st.empty()) st.pop();
       vector<int>right(n);
       for(int i=n-1;i>=0;i--){
           int count=1;
          while(!st.empty()&&st.top().first>arr[i]){
             count+=st.top().second;
             st.pop();
          }
          st.push({arr[i],count});
          right[i]=count;
       }
       int sum=0;
       long long mod=1e9+7;
       for(int i=0;i<n;i++)
       sum=(sum+(((left[i]%mod)*(right[i]%mod))*arr[i]))%mod;
       sum=(sum%mod);
       cout<<sum<<endl;;
    }
}	
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}