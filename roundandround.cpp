#include<bits/stdc++.h>
using namespace std;
void solve(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		string str;
		getline(cin,str);
		getline(cin,str);
		char dir='N';
		pair<int,int> coord;
		coord.first=0;coord.second=0;
		for(int i=0;i<n;i++){
			if(str[i]=='L'){
				if(dir=='N'){
					dir='W';
				}else if(dir=='W'){
					dir='S';
				}else if(dir=='E'){
					dir='N';
				}else{
					dir='E';
				}
			}else if(str[i]=='R'){
				if(dir=='N'){
					dir='E';
				}else if(dir=='W'){
					dir='N';
				}else if(dir=='E'){
					dir='S';
				}else{
					dir='W';
				}
			}else{
				if(dir=='N'){
					coord.second+=1;
				}else if(dir=='W'){
					coord.first-=1;
				}else if(dir=='E'){
					coord.first+=1;
				}else{
					coord.second-=1;
				}
			}
		}
		if(dir!='N' || ((coord.first ==0)   &&   (coord.second==0))){
			cout<<"YES"<<endl;			
		}else{
			cout<<"NO"<<endl;
		}  
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}