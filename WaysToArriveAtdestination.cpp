//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    const int MOD = 1e9 + 7;
    using lli = long long int;
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq;
        vector<lli> dist(n,LLONG_MAX);
        dist[0] =0;
        vector<lli> ways(n,0);
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            lli dis = pq.top().first;
            lli node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int weight = it.second;
                int edge = it.first;
                if(dis + weight < dist[edge]){
                    dist[edge] = dis + weight;
                    pq.push({dis + weight, edge});
                    ways[edge] = ways[node];
                }else if(dis + weight == dist[edge]){
                    ways[edge] = (ways[edge] + ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
