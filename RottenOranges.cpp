//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int countFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                if(grid[i][j]==1)countFresh++;
            }
        }
        int cnt=0;int maxt =0;
        int delI[] = {-1,0,0,1};
        int delJ[] = {0,-1,1,0};
        while(!q.empty()){
            int nrow = q.front().first.first;
            int ncol = q.front().first.second;
            int t = q.front().second;
            q.pop();
            maxt = max(t,maxt);
            for(int i=0;i<4;i++){
                int row = nrow + delI[i];
                int col = ncol + delJ[i];
                if(row>=0 and row<n and col>=0 and col<m and !vis[row][col] and grid[row][col] == 1){
                    q.push({{row,col},t+1});
                    cnt++;
                    vis[row][col] = 2;
                }
            }
        }
            if(countFresh != cnt)return -1;
            return maxt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
