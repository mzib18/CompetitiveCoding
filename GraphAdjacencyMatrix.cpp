#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        //undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}//space - O(n^2)
