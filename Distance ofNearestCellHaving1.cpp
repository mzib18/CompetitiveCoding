//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// }Time Complexity - O(n*M) Space complexity - O(n*M)
class Solution
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   int n= grid.size();
	   int m = grid[0].size();
	   vector<vector<int>> vis(n,vector<int>(m,0));
	   vector<vector<int>> dist(n,vector<int>(m,0));
	   queue<pair<pair<int,int>,int>> q;
	   for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	           if(grid[i][j] == 1){
	               q.push({{i,j},0});
	               vis[i][j] = 1;
	           }
	       }
	   }
	   int delR[] = {-1,0,0,1};
	   int delC[] = {0,-1,1,0};
	   while(!q.empty()){
	       int row = q.front().first.first;
	       int col = q.front().first.second;
	       int d = q.front().second;
	       q.pop();
	       dist[row][col] = d;
	       for(int i=0;i<4;i++){
	           int nrow = row + delR[i];
	           int ncol = col + delC[i];
	           if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==0){
	               q.push({{nrow,ncol},d+1});
	               vis[nrow][ncol] = 1;
	           }
	       }
	   }
	   return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
