#include<bits/stdc++.h>
using namespace std;
//const long long int MOD = 1000000007;
pair<int, int>
findNextValidCell(int x, int y, char ch,multiset<pair<int, int>> *xmt, multiset<pair<int, int>> *ymt) {
    if(ch=='W'){
        while(true) {
            y-=1;
            auto it = xmt[x].upper_bound({y, 1e9});
            if(it!=xmt[x].begin()) --it;
            if(y==it->first) break;
            else if(y==it->second) break;
            else if(y>it->first and y<it->second) break;
        }
        return {x,y};
    }else if(ch=='E'){
        while(true) {
            y+=1;
            auto it = xmt[x].upper_bound({y, 1e9});
            if(it!=xmt[x].begin()) --it;
            if(y==it->first) break;
            else if(y==it->second) break;
            else if(y>it->first and y<it->second) break;
        }
        return {x,y};
    }else if(ch=='N'){
        while(true) {
            x-=1;
            auto it = ymt[y].upper_bound({x, 1e9});
            if(it!=ymt[y].begin()) --it;
            if(x==it->first) break;
            else if(x==it->second) break;
            else if(x>it->first and x<it->second) break;
        }
        return {x,y};
    }else{
        while(true) {
            x+=1;
            auto it = ymt[y].upper_bound({x, 1e9});
            if(it!=ymt[y].begin()) --it;
            if(x==it->first) break;
            else if(x==it->second) break;
            else if(x>it->first and x<it->second) break;
        }
        return {x,y};
    }
}

void iceBeam(int x, int y, multiset<pair<int, int>> *xmt, multiset<pair<int, int>> *ymt) {
    //cout<<x<<" "<<y<<endl;
    auto it = xmt[x].upper_bound({y,1e9});
    //cout<<it->first<<" "<<it->second<<endl;
    if(it!=xmt[x].begin()) --it;
    //cout<<it->first<<" "<<it->second<<endl;
    if(it->first==it->second){
        xmt[x].erase(it);
    }else {
        if (y == it->first) {
            xmt[x].insert({y + 1, it->second});
            xmt[x].erase(it);
        } else if (y == it->second) {
            xmt[x].insert({it->first, y - 1});
            xmt[x].erase(it);
        } else {
            xmt[x].insert({it->first, y - 1});
            xmt[x].insert({y + 1, it->second});
            xmt[x].erase(it);
        }
    }
    //cout<<1<<endl;
    auto it1 = ymt[y].upper_bound({x,1e9});
    //cout<<1<<endl;
    if(it1!=xmt[x].begin()) --it1;
    //cout<<1<<endl;
    if(it1->first==it1->second){
        ymt[y].erase(it1);
       // cout<<1<<endl;
    }else {
        if (x == it1->first) {
            ymt[y].insert({x + 1, it1->second});
            ymt[y].erase(it1);
            //cout<<1<<endl;
        } else if (x == it1->second) {
            ymt[y].insert({it1->first, x - 1});
            ymt[y].erase(it1);
            //cout<<1<<endl;
        } else {
            ymt[y].insert({it1->first, x - 1});
            ymt[y].insert({x + 1, it1->second});
            ymt[y].erase(it1);
            //cout<<1<<endl;
        }
    }
    //cout<<1<<endl;
}

//using namespace std;
pair<int,int>  move(int a,int b,int q,multiset<pair<int,int>> xmt[],multiset<pair<int,int>> ymt[]) {
    while (q--) {
        char ch;
        cin >> ch;
        //cout<<1<<endl;
       pair<int,int> next= findNextValidCell(a, b,ch, xmt, ymt);
       //cout<<"Query"<<q<<" : "<<next.first<<" "<<next.second<<endl;
        iceBeam(a, b, xmt, ymt);
        //cout<<"/////////////////////"<<endl;
    //     auto it = xmt[1].begin();
    //      for (; it != xmt[1].end(); ++it) {
    //     cout << it->first <<" "<<it->second<< " ";
    //     }
 
    // cout <<endl;
    // cout<<"////////"<<endl;
        //cout<<1<<endl;
       a=next.first;
       b=next.second;
       //cout<<1<<endl;
    }
    return {a, b};

}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	int i=1;
	while(i<=t){
		int n,r,c,x,y;
		cin>>n>>r>>c>>x>>y;
		multiset<pair<int,int>> xmt[r];
		multiset<pair<int,int>> ymt[c];
	//	cout<<1<<endl;
		for(int i=0;i<r;i++)xmt[i].insert({0,c-1});
		for(int i=0;i<c;i++)ymt[i].insert({0,r-1});
	//	cout<<t<<endl;
		pair<int,int> ans=move(x-1,y-1,n,xmt,ymt);
	//	cout<<1<<endl;
        //Case #1: 3 2
        cout<<"Case #"<<i<<": "<<(ans.first+1)<<" "<<(ans.second+1)<<endl;
        i++;
	}
}
