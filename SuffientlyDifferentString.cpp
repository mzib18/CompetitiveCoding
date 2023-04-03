#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
void solve(){
    string s;int k;
    cin>>s>>k;
    int p[26];
    memset(p,0,sizeof(p));
    int siz = 0;
    for(int i=0;i<s.length();i++)p[s[i]-'a']++, siz++;
    if(siz-k > 26 - siz){cout<<"NOPE"<<endl;return;}
    string ans="";int temp=k;int cnt =1;
    for(int i=0;cnt<=s.length();i++){
        if(p[i]){
            if(temp){
                ans += (char)('a'+i);
                temp--;cnt++;
            }
        }else{
            ans += (char)('a'+i);
            cnt++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    IOS
    int T;cin>>T;
    while(T--){
        solve();
    }
}
