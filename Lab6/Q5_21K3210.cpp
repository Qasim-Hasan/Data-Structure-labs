//Lab 6
//Question 5
//Qasim Hasan
//21k-3210
//BCS-3J
#include<iostream>
using namespace std;
bool ArraySorted(int a[],int);
int First_Index(int a[],int);
int Second_Index(int a[],int,int);

void UnSortedSubArray(int arr[],int size){
int FirstIndex=0;
int SecondIndex=size-1;
int MaxData;
int MinData;
//Check is the given array is Already Sort or not
if(ArraySorted(arr,size)){
 cout <<"The ARRAY given is already Sorted \n";
}else{
cout <<"The ARRAY given is not Sorted \n";
}
//Consider the First index where the array is becoming unsorted
for (FirstIndex = 0; FirstIndex < size-1; FirstIndex++){
    if (arr[FirstIndex] > arr[FirstIndex+1]){
    break;
    }
}
//Consider the last/second index where the array is becoming sorted again
for(SecondIndex=size-1; SecondIndex > 0; SecondIndex--){
    if(arr[SecondIndex] < arr[SecondIndex-1]){
    break;
    }
}
//get the max and min within the unsorted sub array
MaxData = arr[FirstIndex];
MinData = arr[FirstIndex];
for(int i = FirstIndex + 1; i <= SecondIndex; i++){
    if(arr[i] > MaxData)
    MaxData = arr[i];
    if(arr[i] < MinData)
    MinData = arr[i];
}
//print the indexes where the sub sorted Array should be after sorted
  FirstIndex=First_Index(arr,MinData);
  SecondIndex=Second_Index(arr,size,MaxData);
  //Print the Indexes
if(FirstIndex!=SecondIndex){
  cout << "UnSorted SUBARRAY IS BETWEEN " << FirstIndex << " And " << SecondIndex << endl;
}else{
  cout << "Array has no Sub Array"<< endl;
}
}

int First_Index(int arr[],int min){
int firstindex;
for(int  i = 0; i < firstindex; i++){
    if(arr[i] > min){ 
    firstindex = i; 
    break;
    }     
} 
return firstindex;
}
int Second_Index(int arr[],int n,int max){
int secondindex;
for(int i = n-1; i >= secondindex+1; i--){
    if(arr[i] < max){
    secondindex = i;
    break;
    } 
} 
return secondindex;
}

bool ArraySorted(int arr[],int size){
int i;
for (i= 0; i < size-1; i++){
    if (arr[i] > arr[i+1])
    return 0;
}
if (i==size-1){
    return 1;
}
}

int main(){
    //First Input
    int arr[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    UnSortedSubArray(arr,n);
    cout << endl;
    //Second Input
    int arr1[]={0, 1, 15, 25, 6, 7, 30, 40, 50};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    UnSortedSubArray(arr1,n1);
    cout << endl;
    //Third Input
    int arr2[]={0,4,15,89,98};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    UnSortedSubArray(arr2,n2);
    return 0;
}