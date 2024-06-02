//21K3210
//BCS-3J
//QUESTION 1 PART B
#include<iostream>
using namespace std;
//                     DIRECT RECURSION
int series(int n,int i ,int num)
{
	if(num!=0)
	{
		cout<<n<<"  ";
		n = n+i;
		series(n,i+1,num-1);
	}
	else 
	{
    return 1;
	}
}
int main()
{
	int num;
    int i=0,n=1;
	cout <<"Enter number of elements: " ;
	cin >> num;
	series(n, i, num);
	cout << " " ;
	return 0;
}
