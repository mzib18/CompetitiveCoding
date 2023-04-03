//
// Created by muzammil on 27/01/2023.
//
#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
string print_fraction(int numerator,int denominator){
    lli num = 1ll*numerator;
    lli den = 1ll*denominator;
    if(num == 0)
        return "0";
    int sign = (num<0) ^ (den<0) ? -1 : 1;
     num = abs(num);
     den = abs(den);
    lli intital = num/den;
    string res;
    if(sign==-1)res+="-";
    res+= to_string(intital);
    lli rem = num%den;
    if(rem==0)return res;
    res+=".";
    int index;
    bool repeat=false;
    unordered_map<lli,int> mp;
    while(rem>0 and !repeat){
        if(mp.find(rem) != mp.end()){
            index = mp[rem];
            repeat = true;
            break;
        }else {
            mp[rem] = res.size();
            rem*=10;
            lli quot = rem/den;
            res+= to_string(quot);
            rem = rem%den;
        }
    }
    if(repeat){
        res+=")";
        res.insert(index,"(");
    }
    return res;
}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
    while(t--){
        int numerator,denominator;
        cin>>numerator>>denominator;
        string ans = print_fraction(numerator,denominator);
        cout<<ans<<endl;
    }
}
