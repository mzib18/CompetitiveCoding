#include<iostream>
using namespace std;
int fibo(int n){
    if(n<=1)
        return n;
    return fibo(n-1) + fibo(n-2);

}//brute force
int fibo_2(int n,int *arr){
    if(n<=1){
        return arr[n];
    }
    if(arr[n-1]!=0)arr[n] = arr[n-1];
    else arr[n] = fibo_2(n-1,arr);
    if(arr[n-2]!=0) arr[n] += arr[n-2];
    else arr[n] += fibo_2(n-2,arr);
    return arr[n];
}//Memoization - top-down approach
int fibo_3(int n,int *arr){
    if(n<=1)return arr[n];
    for(int i=2;i<=n;i++)
        arr[i] = arr[i-1] + arr[i-2];
    return arr[n];
}//dynamic programming approach-bottom up way
int main(){
    int n;
    cin>>n;
    int *arr = new int[n+1];
    //cout<<fibo(n)<<endl;
    arr[0]=0;arr[1] = 1;
    for(int i=2;i<=n;i++)arr[i]=0;
    //cout<<fibo_2(n,arr)<<endl;
    cout<<fibo_3(n,arr)<<endl;
    delete [] arr;
}

