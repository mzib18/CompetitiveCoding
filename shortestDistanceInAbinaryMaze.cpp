//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int row = source.first;
        int col = source.second;
        q.push({0,{row,col}});
        dist[row][col] = 0;
        if(row == destination.first and col == destination.second)return 0;
        int delR[] = {0,-1,1,0};
        int delC[] = {-1,0,0,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<4;i++){
                int nrow = r + delR[i];
                int ncol = c + delC[i];
                if(nrow>=0 and nrow <n and ncol>=0 and ncol <m and grid[nrow][ncol] == 1
                and dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis+1;
                    if(nrow == destination.first and ncol == destination.second){
                        return dis+1;
                    }
                    q.push({dis + 1,{nrow,ncol}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
