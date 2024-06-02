//LAB 7
//Question 5
//21K3210
//Qasim Hasan
//BCS-3J
#include<iostream>
using namespace std;
 
int InterPolation_Search(int arr[],int initial,int final,int Data){
    int position;
if(initial<=final&&Data>=arr[initial]&&Data<=arr[final]){
    position=initial+(((double)(final-initial)/(arr[final]-arr[initial]))*(Data -arr[initial]));//position ref taken from slides
    if(arr[position]==Data){
    return position;
    }
    if(arr[position]<Data){
    return InterPolation_Search(arr,position+1,final,Data);
    }
    if(arr[position]>Data){
    return InterPolation_Search(arr,initial,position-1,Data);
        }
    }
    return -1;
}

int Binary_Search(int arr[],int size ,int Data){
    int initial = 0;
    int final = size-1;
    int middle;
    while(initial <= final){
    int mid = initial + (final - initial) / 2;
    if(arr[mid]==Data){
      return mid;
    }
    if(arr[mid]<Data){
      initial=mid + 1;
    }else{
      final=mid - 1;
    }
    }

  return -1;
}
int main(){
int arr[]={2,4,6,8,10,12,14,16,18,20};
int size =sizeof(arr)/sizeof(arr[0]);
int data;
cout << "Enter the data to be search in array using Interpolation Search:";
cin >> data;
int IndexofData = InterPolation_Search(arr,0,size-1,data);
    if(IndexofData!=-1){
        cout << "\nElement data exist at index " << IndexofData;
    }else{
        cout << "\nElement data does not exist";
    }
 cout << endl;   
int arr1[]={2,4,6,8,10,12,14,16,18,20};
int size1=sizeof(arr1)/sizeof(arr1[0]);
int data1;
cout << "Enter the data to be search in array using Binary Search:";
cin >> data1;
int IndexofData1=Binary_Search(arr1,size1,data1); 
    if(IndexofData1!=-1){
        cout << "\nElement data exist at index " << IndexofData1;
    }else{
        cout << "\nElement data does not exist";
    }
}