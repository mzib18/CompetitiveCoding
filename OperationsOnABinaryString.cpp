#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main(){
IOS
int T;cin>>T;
    while(T--){
        int n;int x;
        cin>>n>>x;
        string s;
        cin>>s;
        vector<int> max0substring;
        int ones=0;int zeroes=0;
        for(int i=0;i<n;i++){
            if(s[i]== '0')
                zeroes++;
            if(s[i]== '1' || i==n-1){
                max0substring.push_back(zeroes);
                zeroes=0;
                ones += (s[i] == '1');
            }
        }
        sort(max0substring.begin(),max0substring.end());
        if( x>0 and !max0substring.empty()){
            int k = max0substring.back();
            max0substring.pop_back();
             x -= (2*k+1);
             if(x >= 0){
                ones += k;
             }else{
                x += (2*k+1);
                ones += (x-1)/2;
                x=0;
             }
        }
        cout<<ones<<endl;
    }
}
