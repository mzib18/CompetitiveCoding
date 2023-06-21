#include<bits/stdc++.h>
using namespace std;
char getchar(char c1,char e,char c2,int val){
	int m1,m2;
	if(c1=='x')m1=val;
	else if(c1=='X')m1=1-val;
	else m1=c1-'0';
	if(c2=='x')m2=val;
	else if(c2=='X')m2 = 1-val;
	else m2 = c2-'0';
	if(e=='&'){
		return ('0'+ (m1 & m2));
	}else if(e=='|'){
		return ('0'+ (m1 | m2));
	}else{
		return ('0'+ (m1 ^ m2));
	}
}
int eval(string s,int val){
	if(s[0]=='0'||s[0]=='1')return 0;
	else if(s[0]=='x'|| s[0]=='X')return 1;
	stack<char> st;
	for(int i=0;i<s.length(); i++){
		if(s[i]=='('){
			continue;
		}
		if(s[i]==')'){
			char c2 = st.top();
			st.pop();
			char e = st.top();
			st.pop();
			char c1 = st.top();
			st.pop();
			st.push(getchar(c2,e,c1,val));			
		}else{
			if(s[i]=='x')st.push('0'+ val);
			else if(s[i]=='X')st.push('0'+ 1-val);
			else st.push(s[i]);
		}
	}
	return st.top()- '0';
	}


signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		getline(cin,s);
		getline(cin,s);
		int x = eval(s,0);
		int y = eval(s,1);
		if(x==y){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}
}
