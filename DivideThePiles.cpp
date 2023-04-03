//
// Created by muzammil on 27/01/2023.
//
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int a[n];
    //cout<<1<<endl;
    for(int i=0;i<n;i++)cin>>a[i];
    //sort(a,a+n);
    //cout<<1<<endl;
    int G = __gcd(a[0],a[1]);
    //cout<<1<<endl;
    if(G==1) {cout<< "No"<<endl;return;}
    //cout<<1<<endl;
    int Gn = G;
    for(int i=2;i<n;i++){
        Gn = __gcd(Gn,a[i]);
        //cout<<1<<endl;
        if(Gn == 1){
            cout<<"No"<<endl;
            //cout<<1<<endl;
            return;
        }
    }
    //cout<<1<<endl;
    cout<<"Yes"<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //solve();
    int t;cin>>t;
    while(t--){
        //cout<<1<<endl;
        solve();

    }
}