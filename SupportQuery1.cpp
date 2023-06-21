#include<bits/stdc++.h>
using namespace std;
//construct a bag with add x ,delete x, (minimum,maximum) of elemnts in bag,sum etc
struct bag{
	int sumVal;
	map<int,int> mp;
	bag(){
		sumVal = 0;
		mp.clear();
	}
	void insert(int x){
		mp[x]++;
		sumVal+=x;
	}//logn
	void remove(int x){
		if(mp.find(x)==mp.end())return;
		mp[x]--;
		if(mp[x]==0)
			mp.erase(x);
		sumVal-=x;
	}//logn
	int getMin(){
		if(mp.empty())return -1;
		return mp.begin()->first;
	}//1
	int getMax(){
		if(mp.empty())return -1;
		return mp.rbegin()->first;
	}//1
	int getSum(){
		return sumVal;
	}//1
	int nDistinctELEM(){
		return mp.size();
	}//1
	int getFreqofNextGreaterEq(int x){
		auto it = mp.lower_bound(x);//special function for maps
		if(it==mp.end())
			return -1;
		return it->second;
	}//logn
	int getFreqofPrevSmallerEq(int x){
		auto it = mp.upper_bound(x);//special function for maps
		if(it==mp.begin())
			return -1;
		it--;
		return it->second;
	}//logn

};

void solve(){
	vector<int> arr={1,2,3,4,4,5};
	auto it1 = upper_bound(arr.begin(),arr.end(),4);
	auto it2 = lower_bound(arr.begin(),arr.end(),4);
	cout<<it1-arr.begin()<<endl;
	cout<<it2-arr.begin()<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}