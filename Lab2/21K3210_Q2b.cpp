//21K3210
//BCS-3J
//QUESTION 2 PART B
#include<iostream>
using namespace std;
void series2(int, int, int);
//                        INDIRECT RECURSION
//FUNCTION 1
void series1(int num, int i, int n){
	
	if (num == 0){
		return;
	}else{
		if(i == 0){
			cout << n << "  ";
		}
		cout << n << "  ";
		series2(num - 1, i + 1, n+i);
	}
}
//FUNCTION 2
void series2(int num, int i, int n){
	if (num == 0){
		return;
	}
	series1(num, i, n + 1);
}
int main(){
	int num;
	cout <<"Enter number of elements: " ;
	cin >> num;
	series1(num,0,1);
}