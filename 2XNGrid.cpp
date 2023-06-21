#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

const int inf = 1e9;
const int mod = 1e9 + 7;

signed main(){
    IOS
    lli l,n1,n2;
    cin>>l>>n1>>n2;
    vector<pair<lli,lli>> v1(n1);
    vector<pair<lli,lli>> v2(n2);
    for(int i=0;i<n1;i++){
        cin>>v1[i].first>>v1[i].second;
    }
    for(int i=0;i<n2;i++){
        cin>>v2[i].first>>v2[i].second;
    }


    lli c=0;
    int i=0;int j=0;
    while(i<n1 and j<n2){
        lli small = (v1[i].second <= v2[j].second) ? v1[i].second : v2[j].second;
        if(i < n1 && j < n2 && v1[i].first == v2[j].first)c+=small;
        v1[i].second -= small;
        if(v1[i].second==0)i++;
        v2[j].second -= small;
        if(v2[j].second == 0)j++;

    }
    cout<<c<<endl;
}
