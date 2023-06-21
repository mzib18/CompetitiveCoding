#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int main(){
                  IOS
                 int n;cin>>n;int a[n];
                 for(int i=0;i<n;i++)cin>>a[i];
                 stack<int> s;
                 int prev[n],nxt[n];
                 for(int i=0;i<n;i++){
                                while(!s.empty() and a[s.top()]>=a[i])s.pop();
                                if(!s.empty()){
                                    prev[i]=s.top();           
                                }else{
                                    prev[i]=-1;
                                }
                                s.push(i);
                 }
                 while(!s.empty())s.pop();
                  for(int i=n-1;i>=0;i--){
                                while(!s.empty() and a[s.top()]>=a[i])s.pop();
                                if(!s.empty()){
                                    nxt[i]=s.top();           
                                }else{
                                    nxt[i]=n;
                                }
                                s.push(i);
                 }
                 
                 int ans[n]={};
                 for(int i=0;i<n;i++){
                                int x = nxt[i]-prev[i]-2;
                                ans[x]=max(ans[x],a[i]);
                 }
                 for(int i=n-2;i>=0;i--){
                                ans[i]=max(ans[i],ans[i+1]);               
                 }
                 for(int i=0;i<n;i++){
                                cout<<ans[i]<<" ";
                 }
                 cout<<endl;
}