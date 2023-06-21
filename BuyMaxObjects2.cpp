#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n;
	cin>>q;
	int a[n];
	int prefix[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		prefix[i]=a[i];
		if(i)prefix[i]+=prefix[i-1];
	}
    for(int j=0;j<q;j++){
        int m;
        cin>>m;
        auto it = upper_bound(prefix,prefix+n,m);
        cout<<it-prefix<<endl;
        //cout<<i<<endl;
    }
    return 0;
}