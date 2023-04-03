#include<bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;

void eliminate(int x, int y, multiset<pair<int, int>> *xmt, multiset<pair<int, int>> *ymt);

bool
findCompassNeighbor(int r, int c, int **mat,multiset<pair<int,int>> *xmt, multiset<pair<int, int>> *ymt) {
    bool anyoneEliminated=false;
    multiset<pair<int,int>> toDel;
    for(int i=0;i<r;i++) {
        for (int j = 0; j < c; j++) {
            auto it = xmt[i].upper_bound({j,1e9});
            if(it!=xmt[i].begin()) --it;
            if (j == it->first || j == it->second ||j>it->first and j<it->second) {
                int sumNBH = 0;
                int countNBH = 0;
                int w=j;
                while (w > 0) {
                    w -= 1;
                    auto it = xmt[i].upper_bound({w, 1e9});
                    if (it != xmt[i].begin()) --it;
                    if (w == it->first){
                        sumNBH+=mat[i][w];countNBH+=1;
                        break;
                    }
                    else if (w == it->second) {
                        sumNBH+=mat[i][w];countNBH+=1;
                        break;
                    }
                    else if(w> it->first and w< it->second){
                        sumNBH+=mat[i][w];countNBH+=1;
                        break;
                    }
                }
                int e=j;
                while (e<c-1) {
                    e += 1;
                    auto it = xmt[i].upper_bound({e, 1e9});
                    if (it != xmt[i].begin()) --it;
                    if (e == it->first){
                        sumNBH+=mat[i][e];countNBH+=1;
                        break;
                    }
                    else if (e == it->second) {
                        sumNBH+=mat[i][e];countNBH+=1;
                        break;
                    }
                    else if(e> it->first and e< it->second){
                        sumNBH+=mat[i][e];countNBH+=1;
                        break;
                    }
                }
                int n=i;
                while (n>0) {
                    n -= 1;
                    auto it = ymt[j].upper_bound({n, 1e9});
                    if (it != ymt[j].begin()) --it;
                    if (n == it->first){
                        sumNBH+=mat[n][j];countNBH+=1;
                        break;
                    }else if (n == it->second){
                        sumNBH+=mat[n][j];countNBH+=1;
                        break;
                    }
                    else if (n> it->first and n < it->second){
                        sumNBH+=mat[n][j];countNBH+=1;
                        break;
                    }
                }
                int s=i;
                while (s<r-1) {
                    s += 1;
                    auto it = ymt[j].upper_bound({s, 1e9});
                    if (it != ymt[j].begin()) --it;
                    if (s == it->first){
                        sumNBH+=mat[s][j];countNBH+=1;
                        break;
                    }else if (s == it->second){
                        sumNBH+=mat[s][j];countNBH+=1;
                        break;
                    }
                    else if (s> it->first and s< it->second){
                        sumNBH+=mat[s][j];countNBH+=1;
                        break;
                    }
                }
                float avgskill = 1.0f*sumNBH/countNBH;
                //cout<<i<<" "<<j<<" "<<avgskill<<endl;
                if(mat[i][j]<avgskill){
                    //eliminate(i,j,xmt,ymt);
                    toDel.insert({i,j});
                    anyoneEliminated= true;
                }
            }else{
                continue;
            }
        }
    }
    auto itr= toDel.begin();
    while(itr!=toDel.end()){
        eliminate(itr->first,itr->second,xmt,ymt);
        ++itr;
    }
    return anyoneEliminated;
}//o(n2logn)+o(nlogn)



void eliminate(int x, int y, multiset<pair<int, int>> *xmt, multiset<pair<int, int>> *ymt) {
    auto it = xmt[x].upper_bound({y,1e9});
    if(it!=xmt[x].begin()) --it;
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
    auto it1 = ymt[y].upper_bound({x,1e9});
    if(it1!=xmt[x].begin()) --it1;
    if(it1->first==it1->second){
        ymt[y].erase(it1);
    }else {
        if (x == it1->first) {
            ymt[y].insert({x + 1, it1->second});
            ymt[y].erase(it1);
        } else if (x == it1->second) {
            ymt[y].insert({it1->first, x - 1});
            ymt[y].erase(it1);
        } else {
            ymt[y].insert({it1->first, x - 1});
            ymt[y].insert({x + 1, it1->second});
            ymt[y].erase(it1);
        }
    }
}//o(logn)

//using namespace std;
int  move(int r, int c, int **mat, multiset<pair<int,int>> *xmt, multiset<pair<int,int>> *ymt) {
    int sum=0;
    while (true) {
        //    cout<<"//////////////"<<endl;
        //     for(int i=0;i<r;i++){
        //     auto itr=xmt[i].begin();
        //     cout<<i<<"->";
        //     while(itr!=xmt[i].end()){
        //         cout<<itr->first<<" "<<itr->second<<endl;++itr;
        //     }
        //     }
        // cout<<"//////////////"<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                auto it = xmt[i].upper_bound({j,1e9});
                if(it!=xmt[i].begin()) --it;

                if (j == it->first) {
                    sum+=mat[i][j];
                } else if (j == it->second) {
                    sum+=mat[i][j];
                } else if(j>it->first and j<it->second){
                    sum+=mat[i][j];
                }

            }
        }
        bool isEliminated;
        isEliminated = findCompassNeighbor(r, c,mat, xmt, ymt);
        //cout<<isEliminated<<endl;

        if(!isEliminated)break;
    }
    return sum;

}//o(n2)+o(n2logn)+O(nlogn)

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    int k=1;
    while(k<=t){
        int r,c;
        cin>>r>>c;
        int** mat = new int*[r];

        for (int i = 0; i < r; i++) {

            // Declare a memory block
            // of size n
            mat[i] = new int[c];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                // Assign values to the
                // memory blocks created
                cin>>mat[i][j];
            }
        }//O(n2)
        multiset<pair<int,int>> xmt[r];
        multiset<pair<int,int>> ymt[c];
        for(int i=0;i<r;i++)xmt[i].insert({0,c-1});
        for(int i=0;i<c;i++)ymt[i].insert({0,r-1});
        int interest=move(r,c,mat,xmt,ymt);
        cout<<"Case #"<<k<<": "<<interest<<endl;
        k++;
        for (int i = 0; i < r; i++) // To delete the inner
            // arrays
            delete[] mat[i];
        delete[] mat;
    }//O(n2)+o(n2)+o
}
