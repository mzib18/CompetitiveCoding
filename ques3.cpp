#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
    int h,w;
    cin>>h>>w;
    vector<vector<int>> d2array(h,vector<int>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>d2array[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(d2array[i][j] == 0){
                cout<<".";
            }else{
                char ch = 'a' + (d2array[i][j]-1);
                cout<<ch;
            }
        }
        cout<<endl;
    }
}
