//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//time - O((n*m*4)log(n*m))
// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>> >,
        greater<pair<int,pair<int,int>>>> pq;
        int n= heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {0,-1,1,0};
        int dc[] = {-1,0,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 and col == m-1) return diff;
            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >=0 and nr < n and nc>=0 and nc < m){
                    int newEffort = max(abs(heights[row][col] - heights[nr][nc]),diff);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;

        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }

        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
