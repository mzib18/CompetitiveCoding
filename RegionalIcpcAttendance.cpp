#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
    int T;
    while(T--){
        int n,x,y;
        cin>>n>>x>>y;
        string s;
        getline(cin,s);
        getline(cin,s);
        int maxCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A'){
                if(x>=1){
                    maxCount++;
                    x--;
                }
            }else if(s[i]=='B'){
                if(y>=1){
                    maxCount++;
                    y--;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='C'){
                if(x>=1){
                    maxCount++;
                    x--;
                }else if(y>=1){
                    maxCount++;
                    y--;
                }
            }
        }
        cout<<maxCount<<endl;
    }
}
