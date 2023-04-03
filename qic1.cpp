//
// Created by muzammil on 27/01/2023.
//
#include<bits/stdc++.h>
using namespace std;
//const double pie = 3.141592653589793238462643383279;
int solve(){
    string s;
    getline(cin,s);
    getline(cin,s);
    cout<<"///"<<endl;
    cout<<s<<endl;
    string s2 = "314159265358979323846264338327";
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==s2[i]){
            count++;
        }else{
            break;
        }
    }
    return count;
}
/*0
1
0
0
3
5
12
0
30
*/
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) {
        cout<<solve()<<endl;
    }
}
