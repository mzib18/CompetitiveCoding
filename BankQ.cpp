#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
    int n,q;
    cin>>n>>q;
    priority_queue <int, vector<int>, greater<int>> gq;
    for(int i=1;i<=n;i++){
        gq.push(i);
    }
    set<int> s1;
    vector<int> ans;
    while(q--){
        int instruction;cin>>instruction;
        if(instruction == 1){
                if(!gq.empty()){
                int small = gq.top();
                s1.insert(small);gq.pop();
                }
        }else if(instruction == 2){
                int x;cin>>x;
                auto it = s1.find(x);
                if(it != s1.end()){
                    s1.erase(it);
                }
        }else if(instruction == 3){
                if(!s1.empty()){
                    auto it = s1.begin();
                    ans.push_back(*it);
                }
        }
    }
    for(auto it: ans){
        cout<<it<<endl;
    }
}
