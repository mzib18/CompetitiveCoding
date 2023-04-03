//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int srow,int scol,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[srow][scol] = 1;
        queue<pair<int,int>> q;
        q.push({srow,scol});
        while(!q.empty()){
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for(int deltaR = -1;deltaR<=1;deltaR++){
                for(int deltaC=-1;deltaC<=1;deltaC++){
                    int row = nrow + deltaR;
                    int col = ncol + deltaC;
                    if(row >=0 and row <n and col>=0 and col < m and !vis[row][col] and
                    grid[row][col] == '1'){
                        vis[row][col] =1;
                        q.push({row,col});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}//Time complexity = O(N*M*8)
//Space Complexity = O(N*M*8)
// } Driver Code Ends
