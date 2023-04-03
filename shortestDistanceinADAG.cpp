#include<bits/stdc++.h>
using namespace std;
//time complexity - O(N+M)
using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
class Solution{
private:
    void dfs(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                dfs(it.first,adj,vis,st);
            }
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int n,int m,vector<int> edges[]){
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        int vis[n] = {0};
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        vector<int> dist(n,1e9);
        dist[0] =0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }//relaxing the edges
            }
        }
        return dist;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> edges[m];
        for(int i=0;i<m;i++){
            int u,v,wt;
            cin>>u>>v>>wt;
            edges[i].push_back(u);
            edges[i].push_back(v);
            edges[i].push_back(wt);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n,m,edges);
        for(auto x : res){
            if(x==1e9)cout<<"INF";
            else cout<<x<<" ";
        }
        cout<<"\n";
    }
}
