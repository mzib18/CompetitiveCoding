#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
signed main(){
IOS
    int l1,l2;
    cin>>l1>>l2;
    vector<int> a(l1);vector<int> b(l2);
    for(int i=0;i<l1;i++)cin>>a[i];
    for(int j=0;j<l2;j++)cin>>b[j];
    vector<int> ansA;
    vector<int> ansB;
    int i=0;int j=0;int k=1;
    while(i<l1 || j<l2){
        if(a[i]<b[j]){
            ansA.push_back(k);
            k++;i++;
        }else if(a[i]>b[j]){
            ansB.push_back(k);
            k++;j++;
        }
    }
    while(i<l1){
            ansA.push_back(k);
            k++;i++;
    }
    while(j<l2){
           ansB.push_back(k);
            k++;j++;
    }
    for(auto it : ansA){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it : ansB){
        cout<<it<<" ";
    }
    cout<<endl;
}
