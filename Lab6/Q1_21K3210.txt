//Lab 6
//Question 1
//Qasim Hasan
//21k-3210
//BCS-3J
#include<iostream>
using namespace std;
void BubbleSort(string arr[],int size){
for(int i=0;i<size-1;i++){
   for(int j=0;j<size-i-1;j++){
    if(arr[j]>arr[j+1])
    swap(arr[j],arr[j+1]);
   }
}
}
void PrintArray(string arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
}
int main(){
string name[5]={"Qasim","Aleem","Sufiyaan","Hasan","Fouzan"};
int size=sizeof(name)/sizeof(name[0]);
BubbleSort(name,size);
PrintArray(name,size);
}