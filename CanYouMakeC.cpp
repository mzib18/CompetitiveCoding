#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin >> A >> B >> C;
        int G = __gcd(A, B);
        if(C % G == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}
