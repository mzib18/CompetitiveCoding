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
        int r;cin>>r;
        int c = r-1;
        //map<int,int> mp;
        vector<vector<int>> mat(r, vector<int>(c));
        for(int i=0; i<r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];

            }
        }
        int ans[r];
        int x=mat[0][0];
        if(x!=mat[1][0]) x=mat[2][0];
        ans[0]=x;
        for(int j=0;j<c;j++){
            for(int i=0;i<r;i++){
                if(mat[i][j]!=ans[j]){
                    ans[j+1]=mat[i][j];break;
                }
            }
        }
        for(int i=0;i<r;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
/*4 2 1 3
1 2 3
4 2 1 3 5
1 2 3 4
2 1 3
*/