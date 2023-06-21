#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        for(int i=0;i<n;i++)cin>>arr1[i];
        for(int i=0;i<n;i++)cin>>arr2[i];
        int i=0;
        int covered = -1;
        while(i<n){
            if(arr1[i]==1 and arr2[i]==0){
                cout<<"NO"<<endl;
                break;
            }else if(arr1[i]==0 and arr2[i]==1){
                if(covered==-1){
                    cout<<"NO"<<endl;
                    break;
                }
                if(i>covered){
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(arr1[i]==1){
                covered = i+2;
            }
            i++;
        }
        if(i==n)cout<<"YES"<<endl;
    }

}
