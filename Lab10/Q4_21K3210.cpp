//Lab 10
//Question 4
//Qasim Hasan
//21K-3210
//BCS-3J
#include<iostream>
#include<math.h>
#include<climits>
#define N 5
using namespace std;
class MaxHeap {
  public:
    int * harr; 
  int capacity; 
  int heap_size; 
  MaxHeap(int cap) {
    heap_size = cap;
    capacity = cap;
    harr = new int[cap];
  }
  void printArray() {
    for (int i = 0; i < heap_size; i++)
      cout << harr[i] << " ";
    cout << endl;
  }
  int parent(int i) {
    return (i - 1) / 2;
  }
  int left(int i) {
    return (2 * i + 1);
  }
  int right(int i) {
    return (2 * i + 2);
  }
  int getMin() {
    return harr[0];
  }
  void MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
      smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
      smallest = r;
    if (smallest != i) {
      swap(harr[i], harr[smallest]);
      MaxHeapify(smallest);
    }
  }
  int extractMin() {
    if (heap_size <= 0)
      return INT_MAX;
    if (heap_size == 1) {
      heap_size--;
      return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);
    return root;
  }
  int getcapacity(){
    return capacity;
  }
  void getUnsortedArray() {
   harr[0]=4;
   harr[1]=1;
   harr[2]=3;
   harr[3]=9;
   harr[4]=7;
  }
  void heapSort() {
    int temp[N];
    for (int j=0;j<N;j++) {
      temp[j] = extractMin();
      cout << temp[j] << " ";
    }
  }
};
int main(){
  MaxHeap obj(5);
  obj.getUnsortedArray();
  cout << "Unsorted Array:" << endl;
  obj.printArray();
  for (int i = 5 / 2 - 1; i >= 0; i--) {
    obj.MaxHeapify(i);
  }
  cout << "Heap Sorted Array:" << endl;
  obj.heapSort();
  return 0;
}
