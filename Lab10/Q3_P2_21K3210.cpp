//Lab 10
//Max Heap
//Question 3 Part 2
//21K-3210
//BCS-3J
//Sorting is done is Q4 on max heap
#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
void swap(int & x, int & y) {
  int temp = x;
  x = y;
  y = temp;
}
class MaxHeap{
 public:
    int * harr; 
  int capacity; 
  int heap_size; 

  MaxHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
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
  void insertKey(int k) {
    if (heap_size == capacity) {
      cout << "\n Overflow: Could not insert Key\n";
      return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] < harr[i]) {
      swap(harr[i], harr[parent(i)]);
      i = parent(i);
    }
  }
  void decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
      swap(harr[i],harr[parent(i)]);
      i = parent(i);
    }
  }
  void deleteKey(int data,int &size){
    for(int i=0;i<size;i++){
        if(data==harr[i]){
          decreaseKey(i, INT_MIN);
          extractMax();
        }
    }
    size--;
  }
  void linearSearch(int val) {
    for (int i = 0; i < heap_size; i++) {
      if (harr[i] == val) {
        cout << "Value Found!";
        return;
      }
    }
    cout << "Value NOT Found!";
  }
  int extractMax() {
    if(heap_size == 0){
        cout << "EMPTY HEAP" << endl;
        return -1;
    }else if(heap_size == 1){
        heap_size--;
        return harr[0];
    }else{
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MaxHeapify(0);
        // Return max element
        return root;
    }
  }
  void MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[largest])
      largest = l;
    if (r < heap_size && harr[r] > harr[largest])
      largest = r;
    if (largest != i) {
      swap(harr[i],harr[largest]);
      MaxHeapify(largest);
    }
  }
  void printArray() {
    for (int i = 0; i < heap_size; i++)
      cout << harr[i] << " ";
    cout << endl;
  }
};
int main(){
int arr[]={35,33,42,10,14,19,27,44,26,31};
int size=sizeof(arr)/sizeof(arr[0]);
MaxHeap obj(size);
for(int i=0;i<size;i++){
  obj.insertKey(arr[i]);
}
cout << size << endl;
obj.printArray();
obj.deleteKey(35,size);
cout << size << endl;
obj.deleteKey(42,size);
obj.printArray();
}