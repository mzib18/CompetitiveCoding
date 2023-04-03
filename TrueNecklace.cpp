
#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int k,ans;string b;
vector<string> v;
bool sub(string &s,string &t){
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==t[j])j++;
        if(j==t.length())return true;
    }
 return false;
}
void solve(string s){
        if(s.size()>ans)return;
        bool f = true;
        for(auto it: v)
            f &= sub(s,it);
        if(f){
            if(s.size()<ans){
                b = s;ans = s.length();
            }
            return;
        }
        if(s.length()==16)return;
        solve(s+"B");
        solve(s+"G");
}
int main(){
    IOS
    int T;cin>>T;
        while(T--){
              cin>>k;
              for(int i=0;i<k;i++){
                string s;cin>>s;v.push_back(s);
              }
              string aux = "";b = "";
              ans = inf;
              solve(aux);
              cout<<b<<'\n';
              v.clear();
        }
    return 0;
}
