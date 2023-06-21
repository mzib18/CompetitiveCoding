
#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];int nxt[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pair<int,int> E[n];
    for(int i=0;i<n;i++){
        E[i].second=-i;
        E[i].first = a[i];
    }
    sort(E,E+n);
    set<int> s;
    for(int i=n-1;i>=0;i--){
        auto it = s.upper_bound(-E[i].second);
        if(it==s.end()){
            nxt[-E[i].second]=-1;
        }else{
            nxt[-E[i].second]=*(it);
        }
        s.insert(-E[i].second);
    }
    for(int i=0;i<n;i++){
        cout<<nxt[i]<<" ";
    }
    cout<<endl;
}