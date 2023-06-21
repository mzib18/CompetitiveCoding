#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];int nxt[n];
    for(int i=0;i<n;i++)cin>>a[i];
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty() and a[s.top()]<=a[i])s.pop();
        if(!s.empty()){
            nxt[i]=s.top();
        }else{
            nxt[i]=-1;
        }
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<nxt[i]<<" ";
    }
    cout<<endl;
}
