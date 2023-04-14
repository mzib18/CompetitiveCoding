//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> rank,parent,size;
public:
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
    bool isValid(int adjr,int adjc,int n,int m){
        return adjr>=0 and adjr <n and adjc >=0 and adjc < m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0 , sizeof(vis));
        int cnt=0;vector<int> ans;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int delr[] = {0,-1,1,0};
            int delc[] = {-1,0,0,1};
            for(int i=0;i<4;i++){
                int adjr = row + delr[i];
                int adjc = col + delc[i];
                if(isValid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc] == 1){
                        int node = row * m + col;
                        int adjNode = adjr * m + adjc;
                        if(ds.findUParent(node) != ds.findUParent(adjNode)){
                            cnt--;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;

        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);

        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
