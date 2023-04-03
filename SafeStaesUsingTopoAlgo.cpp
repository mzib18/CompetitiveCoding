//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int inDeg[V] = {0};
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                inDeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0)q.push(i);
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            safeNodes.push_back(temp);
            for(auto it: adjRev[temp]){
                inDeg[it]--;
                if(inDeg[it]==0)q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
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
