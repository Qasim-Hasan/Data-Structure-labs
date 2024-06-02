//Lab 6
//Question 2
//Qasim Hasan
//21k-3210
//BCS-3J
#include<iostream>
using namespace std;
class Sort{
public:
int day;
int month;
int year;
void getmonth(int month){
    this->month=month;
}
void getday(int day){
    this->day=day;
}
void getyear(int year){
    this->year=year;
}

void SelectionSort(Sort S[]){
   int i, j, imin;
   for(i = 0; i<5; i++){
      imin = i;   
      for(j = i+1; j<5; j++){
         if(S[j].year < S[imin].year){
            imin = j;
            swap(S[i], S[imin]);
         } 
   }
}
}

void print(Sort S[]){
for(int i=0;i<5;i++){
    cout << " "<<S[i].day << "     " << S[i].month <<"    "<<S[i].year << endl;
}
}
};
int main(){
Sort SS[5];
SS[0].getday(23);
SS[0].getmonth(9);
SS[0].getyear(2003);

SS[1].getday(21);
SS[1].getmonth(3);
SS[1].getyear(2013);

SS[2].getday(13);
SS[2].getmonth(2);
SS[2].getyear(1996);

SS[3].getday(4);
SS[3].getmonth(11);
SS[3].getyear(2022);

SS[4].getday(12);
SS[4].getmonth(4);
SS[4].getyear(1985);

SS->SelectionSort(SS);
cout<<"[Day][Month][Year]"<< endl;;
SS->print(SS);
}