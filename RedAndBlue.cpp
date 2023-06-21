#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
int helper(string s,int* arr,int n){
    int fixed=-1;int covered = -1;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(i > fixed and s[i]=='B'){
            if(i>covered)return -1;
            ans+=1;
            fixed = covered;
        }
        covered = max(covered, i + arr[i]);
    }
    return ans;
}
signed main(){
IOS
int T;cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int *arr = new int[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<helper(s,arr,n);
    }
}
