//Question 3
//Qasim Hasan
//BCS-3J
//21K-3210
#include<iostream>
using namespace std;

void Rearrange(int a[],int s){
	int temp[s];
	int initial=0;
	int end;
	end=s-1;
	int flag=true;
	for(int i=0;i<s;i++){
		if(flag==true){
			temp[i]=a[end--];
		}else{
			temp[i]=a[initial++];
		}
		flag=!flag;
	}
	for(int i=0;i<s;i++){
		a[i]=temp[i];
	}
}

int main(){
	int arr[10]={43,56,76,88,98,113,432,654,700,987};
	int size;
	size = sizeof(arr)/sizeof(arr[0]);
	cout << "The array before rearranged:";
	for(int i=0;i<size;i++){
		cout << arr[i] <<" ";
	}
	Rearrange(arr,size);
	cout << "\n The array after rearranged:";
	for(int i=0;i<size;i++){
		cout << arr[i] <<" ";
	}
}

