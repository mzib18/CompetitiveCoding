#include<bits/stdc++.h>
using namespace std;
int inf = 1e9;
void solve(){
    int q;cin>>q;
    while(q--){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        stack<int> s1,s2;
        int prev[n],nxt[n];
        for(int i=0;i<n;i++){
            while(!s1.empty() and a[s1.top()]>a[i])s1.pop();
            if(!s1.empty()){
                prev[i]=s1.top();
            }else{
                prev[i]=-1;
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() and a[s2.top()]>=a[i])s2.pop();
            if(!s2.empty()){
                nxt[i]=s2.top();
            }else{
                nxt[i]=n;
            }
            s2.push(i);
        }
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=1LL*(nxt[i]-i)*(i-prev[i])*a[i];
        }
        cout<<sum<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}