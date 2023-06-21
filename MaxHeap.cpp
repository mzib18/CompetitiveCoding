#include<vector>
#include<climits>
#include<iostream>
using namespace std;
class PriorityQueue {
  vector<int> pq; // Declare the data members here

public:
  PriorityQueue() {
    // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/
private:
  void downHeapify() {
    if (getSize() == 1)
      return;
    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    while (leftChildIndex < getSize()) {
      int maxIndex;
      if (rightChildIndex < getSize()) {
        maxIndex = pq[leftChildIndex] > pq[rightChildIndex] ? leftChildIndex
                                                            : rightChildIndex;
        maxIndex = pq[parentIndex] > pq[maxIndex] ? parentIndex : maxIndex;
      } else {
        maxIndex =
            pq[leftChildIndex] > pq[parentIndex] ? leftChildIndex : parentIndex;
      }
      if (maxIndex == parentIndex) {
        break;
      } else {
        int temp = pq[parentIndex];
        pq[parentIndex] = pq[maxIndex];
        pq[maxIndex] = temp;
      }
      parentIndex = maxIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndex = 2 * parentIndex + 2;
    }
  }
  void upheapify() {
    int ei = getSize() - 1;
    int parentIndex = (ei - 1) / 2;
    while (parentIndex >= 0 and pq[parentIndex] < pq[ei]) {
      int temp = pq[parentIndex];
      pq[parentIndex] = pq[ei];
      pq[ei] = temp;
      ei = parentIndex;
      parentIndex = (ei - 1) / 2;
    }
  }

public:
    void insert(int e) {
      pq.push_back(e);
      upheapify(); // Implement the insert() function here
    }

    int getMax() {
      if (isEmpty())
        return INT_MIN;
      return pq[0]; // Implement the getMax() function here
    }

    int removeMax() {
      if (isEmpty())
        return INT_MIN;
      if (getSize() == 1) {
        int r = pq[0];
        pq.pop_back();
        return r;
      }
      int temp = pq[0];
      pq[0] = pq[getSize() - 1];
      pq[getSize() - 1] = temp;
      pq.pop_back();
      downHeapify();
      return temp;// Implement the removeMax() function here
    }

    int getSize() {
      return pq.size(); // Implement the getSize() function here
    }

    bool isEmpty() {
      return pq.size() == 0; // Implement the isEmpty() function here
    }
};
