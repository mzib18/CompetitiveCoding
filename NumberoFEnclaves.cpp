//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int delr[] = {-1,0,0,1};
        int delc[] = {0,-1,1,0};
        for(int i=0;i<n;i++){
            if(!vis[i][0] and mat[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
        }
        for(int j=1;j<m;j++){
            if(!vis[n-1][j] and mat[n-1][j] == 1){
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(!vis[i][m-1] and mat[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int j=1;j<m-1;j++){
            if(!vis[0][j] and mat[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + delr[i];
                int ncol = c + delc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and mat[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 and !vis[i][j])
                    count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
