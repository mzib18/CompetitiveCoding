#include<bits/stdc++.h>
using namespace std;
#define lli long long int
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        lli ans = 1LL * (n *(n-1))/2;
        for(auto it:mp){
            if(it.second>1){
                pq.push({it.second,it.first});
                ans-=1LL*(it.second*(it.second-1))/2;
            }
        }
        for(int i=0;i<k;i++){
            if(pq.empty())break;
            pair<int,int> diff=pq.top();
            pq.pop();
            ans+= diff.first-1;
            if(diff.first>1)pq.push(diff);
        }
        cout<<ans<<endl;
    }
}