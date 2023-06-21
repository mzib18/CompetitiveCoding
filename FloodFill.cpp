//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>>& ans,vector<vector<int>>& image,int newC,int iniC,int delR[],int delC[]){
        ans[sr][sc] = newC;
        int n = image.size();
        int m = image[0].size();
            for(int j=0;j<4;j++){
                int nrow = sr + delR[j];
                int ncol = sc + delC[j];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and ans[nrow][ncol] != newC and image[nrow][ncol]==iniC){
                    dfs(nrow,ncol,ans,image,newC,iniC,delR,delC);
                }
            }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialC = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        int delR[] = {-1,0,0,1};
        int delC[] = {0,-1,1,0};
        dfs(sr,sc,ans,image,newColor,initialC,delR,delC);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}//Time Complexity = O(N*M)
//Space - O(N*M)
// } Driver Code Ends
