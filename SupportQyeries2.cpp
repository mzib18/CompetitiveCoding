#include<bits/stdc++.h>
using namespace std;
struct bag{
	multiset<int> m1;
	multiset<int> m2;
	int sum;
	bag(){
		sum=0;
		m1.clear();
		m2.clear();
	}
	void insert(int x,int k){
	if(m1.size()<k){
		m1.insert(x);
		sum+=x;
	}else{
		if(x>*(m1.begin())){
			m2.insert(*(m1.begin()));
			sum-=*(m1.begin());
			m1.erase(m1.begin());
			m1.insert(x);
			sum+=x;
		}else{
			m2.insert(x);
		}
	}
	}//logn
	void remove(int x){
		if(m1.find(x)!=m1.end()){
			m1.erase(m1.find(x));
			sum-=x;
			if(!m2.empty()){
				m1.insert(*(m2.rbegin()));
				sum+=*(m2.begin());
				m2.erase(m2.lower_bound(*(m2.rbegin())));
			}
		}else if(m2.find(x)!=m2.end()){
			m2.erase(m2.find(x));
		}    
	}//logn
	int add(int k){
		return sum;		
	}//1
	void print(){
	    multiset<int>::iterator it= m1.begin();
	    while(it!=m1.end()){
	        cout<<*(it)<<" ";
	        it++;
	    }
	    cout<<endl;
	    multiset<int>::iterator it2= m2.begin();
	    while(it2!=m2.end()){
	        cout<<*(it2)<<" ";
	        it2++;
	    }
	    cout<<endl;
	}

};
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q,k;
	cin>>q>>k;
	bag bg;
	while(q--){
		int a;
		cin>>a;
		if(a==1){
		    int b;cin>>b;
			bg.insert(b,k);
			bg.print();
		}else if(a == 2){
		    int c;cin>>c;
			bg.remove(c);
			bg.print();
		}else{
		    char ch;cin>>ch;
			int sum = bg.add(k);
			cout<<sum<<endl;
		}
	}
	return 0;
}
/*17 3

1 5

1 2

1 3

1 6

3 ?

2 3

3 ?

2 2

3 ?

2 2

3 ?

2 5

3 ?

2 5

3 ?

2 6

3 ?*/