//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  bool dfs(int node,int vis[],int pathVis[],int checkVis[],vector<int> adj[]){
      vis[node] =1;
      pathVis[node] = 1;
      checkVis[node] = 0;
      for( auto it : adj[node]){
          if(!vis[it]){
              if(dfs(it,vis,pathVis,checkVis,adj)){
                  return true;
              }
          }else if(pathVis[it]){
              return true;
          }
      }
      checkVis[node] = 1;
      pathVis[node] = 0;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int checkVis[V] = {0};
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,checkVis,adj);
            }
        }
        for(int i=0;i<V;i++){
            if(checkVis[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
