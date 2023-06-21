#include<bits/stdc++.h>
using namespace std;
struct value{
    int val,idx;
};
bool compare(value A,value B){
    if(A.val<B.val) return true;
    if(A.val > B.val) return false;
    //A.val == B.val
    if(A.idx>B.idx) return true;
    return false;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];int nxt[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    value E[n];
    for(int i=0;i<n;i++){
        E[i].idx=i;
        E[i].val = a[i];
    }
    sort(E,E+n,compare);
    set<int> s;
    memset(nxt,0,sizeof(nxt));
    for(int i=n-1;i>=0;i--){
        set<int> :: iterator it = s.upper_bound(E[i].idx);
        if(it==s.end()){
            nxt[E[i].idx]=-1;
        }else{
            nxt[E[i].idx]=a[*(it)];
        }
        s.insert(E[i].idx);
    }
    for(int i=0;i<n;i++){
        cout<<nxt[i]<<" ";
    }
    cout<<endl;
}