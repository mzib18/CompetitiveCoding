#include<iostream>
using namespace std;
void upheapify(int s,int e,int* pq) {
  int ei =e;
  int parentIndex = (ei - 1) / 2;
  while (parentIndex >= s and pq[parentIndex] > pq[ei]) {
    int temp = pq[parentIndex];
    pq[parentIndex] = pq[ei];
    pq[ei] = temp;
    ei = parentIndex;
    parentIndex = (ei - 1) / 2;
  }
}
void downHeapify(int s,int e,int* pq) {
  if (s==e)
    return;
  int parentIndex = s;
  int leftChildIndex = 2 * parentIndex + 1;
  int rightChildIndex = 2 * parentIndex + 2;
  while (leftChildIndex <= e) {
    int minIndex;
    if (rightChildIndex <= e) {
      minIndex = pq[leftChildIndex] < pq[rightChildIndex] ? leftChildIndex
                                                          : rightChildIndex;
      minIndex = pq[parentIndex] < pq[minIndex] ? parentIndex : minIndex;
    } else {
      minIndex =
          pq[leftChildIndex] < pq[parentIndex] ? leftChildIndex : parentIndex;
    }
    if (minIndex == parentIndex) {
      break;
    } else {
      int temp = pq[parentIndex];
      pq[parentIndex] = pq[minIndex];
      pq[minIndex] = temp;
    }
    parentIndex = minIndex;
    leftChildIndex = 2 * parentIndex + 1;
    rightChildIndex = 2 * parentIndex + 2;
  }
}
void heapSort(int arr[], int n) {
 for(int i=1;i<n;i++){
     upheapify(0, i, arr);
 }
 for(int i=n-1;i>=0;i--){
   int temp = arr[0];
   arr[0] = arr[i];
   arr[i] = temp;
   downHeapify(0,i-1, arr);
 }
}
int main(){
int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }

    delete[] input;

}
//in-place heap sort time complexity O(nlogn)
// space complexity O(1)
