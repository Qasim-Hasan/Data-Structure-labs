//Lab 6
//Question 3
//Qasim Hasan
//21k-3210
//BCS-3J
#include<iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int temp,j;
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(arr[j]>temp && j>-1){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main(){
    int arr[]={5,6,3,8,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);
    print(arr,size);
    return 0;
}