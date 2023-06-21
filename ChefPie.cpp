#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
void solve(){
    int n;cin>>n;
        vector<int> weight(n);
        for(int i=0;i<n;i++)cin>>weight[i];
        priority_queue<int> pq;
        vector<int> temp(n);
        for(int i=0;i<n;i++)cin>>temp[i];
        sort(weight.begin(),weight.end());
        sort(temp.begin(),temp.end());
        int count=0;
        for(int i=n-1;i>=0;i--){
            for(int j=temp.size()-1;j>=0;j--){
                if(temp[j]>=weight[i]){
                    count++;
                    temp.pop_back();
                    break;
                }
            }
        }
        cout<<count<<endl;

}
signed main(){
    IOS
    int T;cin>>T;
    while(T--){
        solve();
    }
}
