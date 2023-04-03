//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Time -O(N*M) Space - O(N*M)
// User function Template for C++

class Solution{
private :
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis,int delr[],int delc[],int n,int m){
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int row = r + delr[i];
            int col = c + delc[i];
            if(row>=0 and row<n and col>=0 and col<m and !vis[row][col] and grid[row][col] == 'O'){
                dfs(row,col,grid,vis,delr,delc,n,m);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delr[] = {-1,0,0,1};
        int delc[] = {0,-1,1,0};
        for(int i=0;i<n;i++){
            if(!vis[i][0] and mat[i][0] == 'O') dfs(i,0,mat,vis,delr,delc,n,m);
        }
        for(int j=1;j<m;j++){
            if(!vis[n-1][j] and mat[n-1][j] == 'O') dfs(n-1,j,mat,vis,delr,delc,n,m);
        }
        for(int i=n-2;i>=0;i--){
            if(!vis[i][m-1] and mat[i][m-1] == 'O') dfs(i,m-1,mat,vis,delr,delc,n,m);
        }
        for(int j=1;j<m-1;j++){
            if(!vis[0][j] and mat[0][j] == 'O') dfs(0,j,mat,vis,delr,delc,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
