//{ Driver Code Starts
// Initial Template for C++

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
  private:
    bool isValid(int newr,int newc,int n){
        return newr>=0 and newr <n and newc>=0 and newc <n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row =0 ;row <n ;row++){
            for(int col =0; col<n;col++){
                if(grid[row][col] ==0)continue;
                int dr[] = {0,-1,1,0};
                int dc[] = {-1,0,0,1};
                for(int ind =0 ;ind<4;ind++){
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc] == 1){
                            int node = row *n + col;
                            int adjNode = newr *n + newc;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int mx=0;
        for(int row =0 ;row <n ;row++){
            for(int col =0; col<n;col++){
                if(grid[row][col] ==1)continue;
                int dr[] = {0,-1,1,0};
                int dc[] = {-1,0,0,1};
                set<int> components;
                for(int ind =0 ;ind<4;ind++){
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc] == 1){
                            int node = newr * n + newc;
                            components.insert({ds.findUParent(node)});
                        }
                    }
                }
                int sizeT=1;
                for(auto it : components){
                    sizeT += ds.size[it];
                }
                mx = max(mx,sizeT);
            }
        }
        for(int cell =0;cell <n*n;cell++){
            mx = max(mx,ds.size[ds.findUParent(cell)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends
