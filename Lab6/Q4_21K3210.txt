//Lab 6
//Question 4
//Qasim Hasan
//21k-3210
//BCS-3J
#include<iostream>
using namespace std;
void BubbleSort(int arr[],int size){
for(int i=0;i<size-1;i++){
    for(int j=0;j<size-1-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
}
}
void print(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int getMaxToysCount(int k,int n,int arr[]){
int count=0;
int sum=arr[0];
for(int i=1;i<n;i++){
    if(sum<=k){
        sum=sum+arr[i];
        count++;
    }
}
return count;
}
int main(){
int arr[7]={1, 12, 5, 111, 200, 1000, 10};
int n=sizeof(arr)/sizeof(arr[0]);
BubbleSort(arr,n);
print(arr,n);
cout << "Count:" <<getMaxToysCount(50,n,arr);
}