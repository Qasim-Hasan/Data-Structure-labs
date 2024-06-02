//21K3210
//BCS-3J
//QUESTION5 Part b
#include<iostream>
using namespace std;
bool safe(int** arr, int x,int y, int n){
	if((x<n) && (y<n) && arr[x][y]==1){
		return true;
	}else{
	return false;
}
}
bool maze(int** arr, int x, int y, int n, int** sol){
	if((x==(n-1)) && (y==(n-1))){
		sol[x][y] = 1;
		return true;
	}
	if (safe(arr, x, y,n)){
		sol[x][y] = 1;
		if(maze(arr, x+1, y, n, sol)){
			return true;
		}
		if(maze(arr, x, y+1, n, sol)){
			return true;
		}	
		sol[x][y]=0;
		return false;
	}
	return false;
}
int main(){
	int n;
	cout <<"Enter number of elements in rows and columns:";
	cin >> n;
	int** arr = new int* [n];
	for(int i=0; i<n; i++){
		arr[i]= new int[n];
	}
	cout<<"\n Enter array  elements\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << "a["<<i<<"]"<<"["<<j<<"]:";
			cin >> arr[i][j];
			cout << endl;
		}
	}
	int** sol = new int*[n];
	for(int i=0; i<n; i++){
	sol[i]= new int[n];
		for(int j=0; j<n; j++)	{
			sol[i][j] = 0;
		}
	}
	cout << " \nSolution exist\n" ;
	if(maze(arr,0,0, n, sol)){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout  << sol[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << "Does not have a solution\n";
	}
	return 0;
}