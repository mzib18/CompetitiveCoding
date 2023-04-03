//
// Created by muzammil on 27/01/2023.
//
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,s,r;
        cin>>n>>s>>r;
        int cal=n-1;
        int tot = r-cal;
        vector<int> rSequence(cal,1);
        int i=0;
        while(tot){
            rSequence[i]+=1;
            i+=1;i%=cal;
            tot-=1;
        }
        int last=s-r;
        for(int j=0;j<rSequence.size();j++){
            cout<<rSequence[j]<<" ";
        }
        cout<<last<<endl;
    }
}
