//21K3210
//BCS-3J
//QUESTION 3
#include <iostream>
using namespace std;
void SortingArray(int array[], int size){
    if (size == 1)
        return;
    int count = 0;
    for (int i=0; i<size-1; i++)
        if (array[i] > array[i+1]){
            swap(array[i], array[i+1]);
            count++;
        }
      if (count==0)
           return;
    SortingArray(array, size-1);
}
void printArray(int arr[], int n){
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
} 
int main(){
    int arr[] = {9,3,3,6,4,22,74,2,64};
    int n = sizeof(arr)/sizeof(arr[0]);
    SortingArray(arr, n);
    printf("Sorted array is given as: \n");
    printArray(arr, n);
    return 0;
}