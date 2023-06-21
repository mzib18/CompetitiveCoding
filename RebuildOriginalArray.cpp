
#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main(){
    clock_t start, end;
     /* Recording the starting clock tick.*/
    start = clock();
    IOS
    int n;cin>>n;
    vector<int> a;
    for(int i=0;i<pow(2,n);i++){
        int j;cin>>j;
        a.push_back(j);
    }
        sort(a.begin(),a.end());
        vector<int> ans;
        while(n--){
            unordered_map<int,int> mp;
            bool on =false;
            vector<int> ss0,ss1;
            int diff=a[1]-a[0];
            for(auto &x : a){
                if(!mp[x]){
                    ss0.push_back(x);
                    mp[x+diff]++;
                    if(x==0) on = true;
                }else{
                    ss1.push_back(x);
                    mp[x]--;
                }
            }
            if(on){
                a=ss0;
                ans.push_back(diff);
            }else{
                a=ss1;
                ans.push_back(-diff);
            }
        }
        for(int &i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
        end = clock();
         double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    }
