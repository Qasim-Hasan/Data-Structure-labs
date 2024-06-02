#include<iostream>
#include<iostream>
#include<string>
using namespace std;
void ascending(int *array2){
	int *p[10];
	int *tempvar;
	for(int i=0;i<10;i++){
		p[i]=&array2[i];
	}
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			if(*p[i]>*p[j]){
				tempvar=p[i];
				p[i]=p[j];
				p[j]=tempvar;
			}
		}
	}
	for(int i=0;i<10;i++){
		cout << *p[i]<<" ";
	}
	cout << endl;
}
void decending(int *array1){
	int *ptr[10];
	int *temp;
	for(int i=0;i<10;i++){
		ptr[i]=&array1[i];
	}
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			if(*ptr[i]<*ptr[j]){
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
	for(int i=0;i<10;i++){
		cout << *ptr[i]<<" ";
	}
	cout << endl;
}
int main(){
	int array[10];
	int op=0;
	cout << "Enter data: \n";
	for(int i=0;i<10;i++){
	    cout << i <<" ";
		cin >> array[i];
	}
	cout << "Enter any choice :\n";
	cout << "1. Ascend \n";
	cout << "2. Decend \n";
	cin >> op;
	if(op==1){
		ascending(array);
	}else if(op==2){
		decending(array);
	}else{
		cout << "wrong input";
	}
}



