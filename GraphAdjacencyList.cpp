#include<bits/stdc++.h>
// 1-Based Graph
using namespace std;
void depthFirstSearch(int node,vector<int> adj[],int vis[],vector<int>& dfs){
     vis[node] = 1;
     dfs.push_back(node);
     for(auto it : adj[node]){
        if(!vis[it]){
            depthFirstSearch(it,adj,vis,dfs);
        }
     }
}//time complexity - O(V +2*E) Space Complexity - O(V)
vector<int> breadthFirstSearch(int n, vector<int> adj[]) {
    int vis[n + 1];
    memset(vis, 0, sizeof(vis)); // initialize vis array with 0
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}//time comlexity - O(V+2*E)
//space complexity - O(V)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        //undirected  graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs = breadthFirstSearch(n, adj);
    int vis[n+1];memset(vis, 0, sizeof(vis));
	vector<int> dfs;
    depthFirstSearch(1, adj,vis,dfs);
    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < dfs.size(); i++) {
        cout << dfs[i] << " ";
    }
    cout << endl;
    return 0;
}
