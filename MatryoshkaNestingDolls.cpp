//
// Created by muzammil on 29/01/2023.
//

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
    IOS
    int t;cin>>t;
    while(t--){
        map<int,int> mp;
        int n;cin>>n;int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int ans = 0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(!mp[a[i]-1])ans++;
            else mp[a[i]-1]--;
            mp[a[i]]++;
        }
        cout<<ans<<endl;
    }//o(nlogn)
}
/*2
1
6
2
2
2
2
2
4
3*/