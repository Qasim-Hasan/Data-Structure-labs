//Question 4
//Qasim Hasan
//BCS-3J
//21K-3210
#include<iostream>
using namespace std;

class F{
	public:	
	static int count;
	bool (*Friendlist)[5];
	
	F(bool f[5][5]):Friendlist(f){
	}
	static int c;
	void printlistoffriend(){
		cout <<"   0  1  2  3  4 \n";
		 for(int i=0; i<5; i++)
        {
        	cout <<c<<" ";
        	c++;
                for(int j=0; j<5; j++)
                {
                        if(Friendlist[i][j]==0){
                        	cout<<" "<<" "<<" ";
						}else{
							cout<<" "<<"*"<<" ";
						}
                }
                cout<<"\n";
        }
	}
	void commonfriend(){
		int a,b;
		cout << "\n Enter any two friends (0-4) to find a common friend on the list";
		cout << "\n enter first friend: ";
		cin >> a;
		cout << "\n enter second friend: ";
		cin >> b;
		cout << endl;
		
	for(int j=0;j<5;j++){
		if(Friendlist[a][j]==1&&Friendlist[b][j]==1){
			if(Friendlist[a][j]==Friendlist[b][j]){
			count++;
			cout << "\nFriend "<< a <<" and "<< b <<" common friend : " <<  j <<"\n";
		}	
		}
	}
	
	cout <<"\n Friend "<< a <<" and "<< b <<"  have  " << count <<" common friends";
	
	}
};
int F::count=0;
int F::c=0;

int main(){
	bool Friendlist[5][5]={{false,true,false,true,true},{true,false,true,false,true},{false,true,false,false,false},{true,false,false,false,true},{true,true,false,true,false}};
	F obj(Friendlist);
	obj.printlistoffriend();
	obj.commonfriend();
	return 0;
}
