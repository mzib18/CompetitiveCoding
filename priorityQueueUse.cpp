#include<iostream>
#include "PriorityQueue.h"

using namespace std;
int main(){
 Priority_Queue pq;
 pq.insert(12);
 pq.insert(6);
 pq.insert(5);
 pq.insert(100);
 pq.insert(1);
 pq.insert(9);
 pq.insert(0);
 pq.insert(14);
 while(!pq.isEmpty()){
 cout<<pq.getMin()<<endl;
 pq.removeMin();
 }
}
