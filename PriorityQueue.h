#include<vector>
using namespace std;
class Priority_Queue{
    vector<int> pq;
public:
    Priority_Queue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty())return 0;
        return pq[0];
    }
private:
    void downHeapify(){
        if(getSize()==1)return;
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        while(leftChildIndex < getSize()){
            int minIndex;
            if(rightChildIndex < getSize()){
                minIndex = pq[leftChildIndex]<pq[rightChildIndex] ? leftChildIndex : rightChildIndex;
                minIndex = pq[parentIndex] < pq[minIndex] ? parentIndex : minIndex;
            }else{
                minIndex = pq[leftChildIndex]<pq[parentIndex] ? leftChildIndex : parentIndex;
            }
            if(minIndex == parentIndex){
                    break;
            }else{
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
            }
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;
        }
    }
    void upheapify(){
        int ei = getSize()-1;
        int parentIndex = (ei-1)/2;
        while(parentIndex>=0 and pq[parentIndex] > pq[ei]){
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[ei];
            pq[ei] = temp;
            ei = parentIndex;
            parentIndex = (ei-1)/2;
        }
    }
public:
    void insert(int e){
       pq.push_back(e);
       upheapify();
    }
    void removeMin(){
        if(isEmpty())return;
        if(getSize()==1){
         pq.pop_back();return;
        }
        int temp = pq[0];
        pq[0] = pq[getSize()-1];
        pq[getSize()-1] = temp;
        pq.pop_back();
        downHeapify();
    }
};
