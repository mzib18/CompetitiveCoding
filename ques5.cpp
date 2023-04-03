#include<bits/stdc++.h>
using namespace std;

using lld = double;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> takashi;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        takashi.push_back({a,b});
    }
    vector<pair<int,int>> aoki;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        aoki.push_back({a,b});
    }
    priority_queue<lld,vector<lld>,greater<lld>> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            lld ans = 100.0d * (takashi[i].first+aoki[j].first)/((takashi[i].first+aoki[j].first)+(takashi[i].second*aoki[j].second));
            if(pq.size()<k){
                    pq.push(ans);
            }else{
                    lld t = pq.top();
                    if(t<ans){
                        pq.pop();
                        pq.push(ans);
                    }
            }
        }
    }
    while(!pq.empty()){
        cout<<setprecision(15);
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
