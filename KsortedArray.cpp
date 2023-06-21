#include<iostream>
#include<queue>
using namespace std;
void ksortedArray(int *arr,int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++)pq.push(arr[i]);
    int j=0;
    for(int i=k;i<n;i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while(!pq.empty()){
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main(){
//default - max priority queue
   /* priority_queue<int> pq;
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);
    cout<<"Size :"<<pq.size()<<endl;
    cout<<"Top :"<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }*/
    int arr[] = {10,12,6,7,9};
    int k=3;
    ksortedArray(arr,5,k);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
}
