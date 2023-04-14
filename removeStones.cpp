//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{

public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i] = i;
    }
    inline int findUParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v){
    int ultimateParentU = findUParent(u);
    int ultimateParentV = findUParent(v);
    if(ultimateParentU == ultimateParentV)return;
    if(rank[ultimateParentU] < rank[ultimateParentV]){
        parent[ultimateParentU] = ultimateParentV;
    }else if(rank[ultimateParentU] > rank[ultimateParentV]){
        parent[ultimateParentV] = ultimateParentU;
    }else{
        parent[ultimateParentV] = ultimateParentU;
        rank[ultimateParentU]++;
    }
    }
    void unionBySize(int u,int v){
        int ultimateParentU = findUParent(u);
        int ultimateParentV = findUParent(v);
        if(ultimateParentU == ultimateParentV)return;
        if(size[ultimateParentU] < size[ultimateParentV]){
                parent[ultimateParentU] = ultimateParentV;
                size[ultimateParentV] += size[ultimateParentU];
        }else{
               parent[ultimateParentV] = ultimateParentU;
               size[ultimateParentU] += size[ultimateParentV];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow =0;
        int maxColumn =0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxColumn = max(maxColumn , it[1]);
        }
        DisjointSet ds(maxRow + maxColumn + 1);
        unordered_map<int,int> mp;
        for(auto it : stones){
            int node = it[0];
            int adjNodes = it[1] + maxRow + 1;
            ds.unionBySize(node,adjNodes);
            mp[node] = 1;
            mp[adjNodes] = 1;
        }
        int cnt =0;
        for(auto it : mp){
            if(ds.findUParent(it.first) == it.first)cnt++;
        }
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
