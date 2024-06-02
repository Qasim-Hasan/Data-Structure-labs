//21K3210
//BCS-3J
//QUESTION 1 PART A
#include<iostream>
using namespace std;
//                     DIRECT RECURSION
int series(int n, int i , int num)
{
	if(num!=0){
	i = i+n;
	cout<<i<<"  ";
	series(n+1,i+1,num-1);
	}else{
		return 1;
	}
}
int main()
{
	int i=1,n=0;
    int num;
	cout <<"Enter number of elements to generate a Series: " ;
	cin >> num;
	series(n, i, num);
	cout << " " ;
	return 0;
}