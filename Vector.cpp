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
	vector<int> v;
	//access
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	cout<<v[0]<<endl;
	cout<<v[1]<<endl;
	cout<<v[2]<<endl;
	//change
	v[1]=100;
	cout<<v[0]<<endl;
	cout<<v[1]<<endl;
	cout<<v[2]<<endl;
	cout<<"Size"<<v.size()<<endl;
	cout<<v.at(2)<<endl;
	//cout<<v.at(6)<<endl;// at is much safer
	v.pop_back();//remove last elemnt
	cout<<v.at(0)<<endl;
	cout<<v.at(1)<<endl;
	//cout<<v.at(2)<<endl;
	//2d vectors;
	int m=4;int n=3;
	vector<vector<int>> v2d(m,vector<int>(n,0));
	for(int i=0;i<v2d.size();i++){
		for(int j=0;j<v2d[i].size();j++){
			cin>>v2d[i][j];
		}
	}
	for(int i=0;i<v2d.size();i++){
		for(int j=0;j<v2d[i].size();j++){
			cout<<v2d[i][j]<<" ";
		}
		cout<<endl;
	}
		
}
