#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
vector<int>* removeDuplicates(int *arr,int n){
    vector<int>* output = new vector<int>();
    unordered_map<int,bool> mp;
    for(int i=0;i<n;i++){
        if(mp.count(arr[i])> 0)continue;
        mp[arr[i]] = true;
        output->push_back(arr[i]);
    }
    return output;
}
int main(){
   /* unordered_map<string,int> mp;
    pair<string,int> p("abc",1);
    mp.insert(p);
    mp["def"]=2;
    cout<<mp["abc"]<<endl;
    cout<<mp.at("abc")<<endl;
    //cout<<mp.at("ghi")<<endl;//gives error if not present
    cout<<mp["ghi"]<<endl;//if not present then it inserts the key with default value 0
    if(mp.count("ghi")>0){
        //it exists
    }else{
        //it does not exists
    }
    cout<<mp.size()<<endl;//size of map
    mp.erase("abc");*/
    int a[] ={1,2,3,4,3,4,5,7,9,0,1,2};
    vector<int>* ans = removeDuplicates(a,12);
    for(int i=0;i<ans->size();i++)cout<<ans->at(i)<<" ";
    cout<<endl;
}
