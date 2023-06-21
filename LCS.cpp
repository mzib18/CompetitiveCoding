#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
void print2Darray(int **output,int m,int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int lcs_dp(string s,string t,int** output){
    int m=s.length();
    int n=t.length();
    for(int i=0;i<m+1;i++)
        output[i][0] = 0;
    for(int j=0;j<n+1;j++)
        output[0][j] =0;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[i-1]==t[j-1])
                output[i][j] = 1+output[i-1][j-1];
            else
                output[i][j] = max(output[i-1][j-1],max(output[i-1][j],output[i][j-1]));

        }
    }
    return output[m][n];
}
int lcs_mem(string s,string t,int** output){
    int m=s.length();
    int n=t.length();
    if(s.length()==0 || t.length()==0)
        return 0;//base case
    if(output[m][n] !=-1 )
            return output[m][n];
    //recursive calls
    int ans=0;
    if(s[0]==t[0]){
        ans=1+lcs_mem(s.substr(1),t.substr(1),output);
    }else{
        ans=max(lcs_mem(s.substr(1),t.substr(1),output),max(lcs_mem(s,t.substr(1),output),lcs_mem(s.substr(1),t,output)));
    }
    output[m][n] = ans;
    print2Darray(output,m,n);
    return ans;
}
int lcs(string s,string t){
    if(s.length()==0 || t.length()==0)
        return 0;//base case
    //recursive calls
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }else{
        return max(lcs(s.substr(1),t.substr(1)),max(lcs(s,t.substr(1)),lcs(s.substr(1),t)));
    }
}
int main(){
    string s;string t;
    cin>>s>>t;
     int m = s.length();int n=t.length();
    int** output = new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i] = new int[n+1];
        for(int j=0;j<n+1;j++){
            output[i][j]=-1;
        }
    }
    cout<<"Count of longest common subsequence is: "<<lcs(s,t)<<endl;
    //cout<<"Count of longest common subsequence is: "<<lcs_mem(s,t,output)<<endl;
    cout<<"Count of longest common subsequence is: "<<lcs_dp(s,t,output)<<endl;

    for(int i=0;i<m+1;i++){
        delete [] output[i];
    }
    delete [] output;
}
