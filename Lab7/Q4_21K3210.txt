//LAB 7
//Question 4
//21K3210
//Qasim Hasan
//BCS-3J
#include<iostream>
using namespace std;
 
int Gap_Next(int GAP){
GAP=(GAP*10)/13;
if(GAP<1){
return 1;
}
return GAP;
}
void DisplayArray(int arr[],int size){
    int i=0; 
    for(i=0;i<size;i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
}

void CombSortingAscending(int arr[],int n){
    bool IsFound=true;
    int Gap=n;
    while(Gap!=1||IsFound==true){
    Gap= Gap_Next(Gap);
    IsFound =false;
    for(int i=0;i<n-Gap; i++){
    if(arr[i]>arr[i+Gap]){
    swap(arr[i],arr[i+Gap]);
    IsFound = true;
    }
}
}
}
void CombSortingDescending(int arr[],int n){
    bool IsFound=true;
    int Gap=n;
    while(Gap!=1||IsFound==true){
    Gap=Gap_Next(Gap);
    IsFound=false;
    for(int i=0; i<n-Gap; i++){
    if(arr[i]<arr[i+Gap]){
    swap(arr[i],arr[i+Gap]);
    IsFound=true;
    }
}
}
}
 
int main(){
    cout << "\n Array in Ascending:";
    int arr[] = {32,41,643,2,52,12,-2,-322};
    int size = sizeof(arr)/sizeof(arr[0]);
    CombSortingAscending(arr, size);
    DisplayArray(arr,size);

    cout << "\n Array in Descending:";
    int arr1[] = {32,41,643,2,52,12,-2,-322};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    CombSortingDescending(arr1, size1);
    DisplayArray(arr1,size1);
    cout << endl;
}