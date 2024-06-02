//LAB 7
//Question 1
//21K3210
//Qasim Hasan
//BCS-3J
#include<iostream>
using namespace std;
//Merge Sort
int MaxElement(int arr[],int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
void MergeSort(int arr[],int initial,int middle,int final,int MaximumElement){
int temp1=initial;
int temp2=middle+1;
int temp3=initial;
while(temp1<=middle && temp2 <= final){
    if(arr[temp1]%MaximumElement <= arr[temp2]%MaximumElement){
       arr[temp3]=arr[temp3]+(arr[temp1]%MaximumElement)*MaximumElement;
       temp1++;
       temp3++;
    }else{
       arr[temp3]=arr[temp3]+(arr[temp2]%MaximumElement)*MaximumElement;
       temp2++;
       temp3++;
    }
}
while(temp1<=middle){
    arr[temp3] = arr[temp3]+(arr[temp1]%MaximumElement)*MaximumElement;
    temp3++;
    temp1++;
}
while(temp2<=final){
    arr[temp3] = arr[temp3]+(arr[temp2]%MaximumElement)*MaximumElement;
    temp2++;
    temp3++;
}
for (int e = initial; e <= final; e++){
        arr[e] = arr[e] / MaximumElement;
}
}
void MergeSortArray(int arr[],int initial,int final,int MaximumElement){
 if(initial<final){
 int middle=(initial+final)/2;
 MergeSortArray(arr,initial,middle,MaximumElement);
 MergeSortArray(arr,middle+1,final,MaximumElement);
 MergeSort(arr,initial,middle,final,MaximumElement);
 }
}
void DisplayArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[]={54,87,65,76,32,9,7,32,96};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array before Merge Sort:";
    DisplayArray(arr,size);
    int MaximumElement=MaxElement(arr,size)+1;
    MergeSortArray(arr,0,size-1,MaximumElement);
    cout << "Array after Merge Sort: ";
    DisplayArray(arr,size);
    cout << endl;
    int arr1[]={999,612,589,856,56,945,243};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    cout << "Array before Merge Sort:";
    DisplayArray(arr1,size1);
    int MaximumElement1=MaxElement(arr1,size1)+1;
    MergeSortArray(arr1,0,size1-1,MaximumElement1);
    cout << "Array after Merge Sort: ";
    DisplayArray(arr1,size1);
    cout << endl;
}