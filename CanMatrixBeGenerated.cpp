#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
bool isValid(vector<vector<int>> &mat,int n,int r,int c){
  int i = r;
  while (i + 1 < n) {
    if (mat[i + 1][c] == 1)
      return false;
    i++;
  }
  i = r;
  while (i - 1 >= 0) {
    if (mat[i - 1][c] == 1)
      return false;
    i--;
  }
  int j = c;
  while (j + 1 < n) {
    if (mat[r][j + 1] == 1)
      return false;
    j++;
  }
  j = c;
  while (j - 1 >= 0) {
    if (mat[r][j - 1] == 1)
      return false;
    j--;
  }
  i = r;
  j = c;
  while (i + 1 < n and j + 1 < n) {
    if (mat[i + 1][j + 1] == 1)
      return false;
    i++;
    j++;
  }
  i = r;
  j = c;
  while (i - 1 >= 0 and j - 1 >= 0) {
    if (mat[i - 1][j - 1] == 1)
      return false;
    i--;
    j--;
  }
  i = r;
  j = c;
  while (i - 1 >= 0 and j + 1 < n) {
    if (mat[i - 1][j + 1] == 1)
      return false;
    i--;
    j++;
  }
  i = r;
  j = c;
  while (i + 1 < n and j - 1 >= 0) {
    if (mat[i + 1][j - 1] == 1)
      return false;
    i++;
    j--;
  }
  return true;
}
void Nqueen(vector<vector<int>> &matrix,int n,int r){
    if(r==n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
        return;
    }
    for(int j=0;j<n;j++){
        for(int k=1;i<=k*k;k++){
            if(isValid(matrix,n,r,j,k)){
                matrix[r][j] = k;
                Nqueen(matrix,n,r+1);
                matrix[r][j] = -1;
            }
        }
    }
}
signed main(){
IOS
    int t;cin>>t;
    while(t--){
     int n;cin>>n;
        vector<vector<int>> v(n,vector<int>(n,0));
        Nqueen(v,n,0);
        return 0;
    }
}
