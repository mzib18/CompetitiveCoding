//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int countExtra=0;
            for(auto it :edge){
                int u= it[0];
                int v = it[1];
                if(ds.findUParent(u) == ds.findUParent(v)){
                    countExtra++;
                }else{
                    ds.unionBySize(u,v);
                }
            }
        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                nc++;
            }
        }
        int ans=nc-1;
        if(countExtra>=ans)return ans;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
