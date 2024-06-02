//Question 5
//Qasim Hasan
//BCS-3J
//21K-3210
#include<iostream>
using namespace std;
#include <string>

class F{
	private:
		int *array1;
		float **array2;
		int size;
		
	public:
		F(int s){
			size = s;
			array2 = new float*[size];
			array1 = new int[size];
		}
		
		void storeData(){
			for (int i = 0; i < size; i++)
			{
				cout << "Enter total subjects for student "<<i+1<<": ";
				cin >> array1[i];
				array2[i] = new float[array1[i]];
			}
			
			for(int i=0;i<size;i++){
				for(int j=0;j<array1[i];j++){
					cout << "Student " <<i+1<<" Subject "<<j+1<<" marks: ";
					cin>>array2[i][j];
				}
			}
		}
		
		void getGpa(){
			for (int i = 0; i < size; i++)
			{
		        float temp=0,gpa;
				cout << "OVER ALL GPA OF (STUDENT "<<i+1<<")\n";
				for (int j = 0; j < array1[i]; j++)
				{
					temp=temp+3*array2[i][j];
				}
				gpa=temp/(array1[i]*3);
				cout << " GPA:"<< gpa << endl;
				cout << "\n";
			}
		}
		
		~F(){
			for (int i = 0; i < size; i++){
				delete[] array2[i];
			}
				delete[] array2;
				delete[] array1;
		}
};

int main(){
	int students=5;	
	F st(students);
	st.storeData();
	st.getGpa();
	


	system("pause");
	return 0;
}
