#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i] = i;
    }
    inline int findUParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v){
    int ultimateParentU = findUParent(u);
    int ultimateParentV = findUParent(v);
    if(ultimateParentU == ultimateParentV)return;
    if(rank[ultimateParentU] < rank[ultimateParentV]){
        parent[ultimateParentU] = ultimateParentV;
    }else if(rank[ultimateParentU] > rank[ultimateParentV]){
        parent[ultimateParentV] = ultimateParentU;
    }else{
        parent[ultimateParentV] = ultimateParentU;
        rank[ultimateParentU]++;
    }
    }
    void unionBySize(int u,int v){
        int ultimateParentU = findUParent(u);
        int ultimateParentV = findUParent(v);
        if(ultimateParentU == ultimateParentV)return;
        if(size[ultimateParentU] < size[ultimateParentV]){
                parent[ultimateParentU] = ultimateParentV;
                size[ultimateParentV] += size[ultimateParentU];
        }else{
               parent[ultimateParentV] = ultimateParentU;
               size[ultimateParentU] += size[ultimateParentV];
        }
    }



};
int main(){

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findUParent(3) == ds.findUParent(7)){
        cout<<"Same\n";
    }else{
        cout<<"Not same\n";
    }
    ds.unionBySize(3,7);
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout<<"Same\n";
    }else{
        cout<<"Not same\n";
    }
    return 0;
}
