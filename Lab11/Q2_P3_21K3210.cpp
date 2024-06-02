//Qasim Hasan
//Lab 11
//21K-3210
//BCS-3J
//QUESTION 2 PART 3

//HASH FUNCTION (MID SQUARE)

#include<iostream>
using namespace std;
const int Tablesize =1000;
class HashTableEntry{
    public:
    int key;
    int value;
    HashTableEntry(int k,int v){
        this->key=k;
        this->value=v;
    }
};
class HashMapTable{
    private:
    HashTableEntry **T;
    public:
    HashMapTable(){
        T=new HashTableEntry*[Tablesize];
        for(int i;i<Tablesize;i++){
            T[i]=NULL;
        }
    }
    int HashFunc(int value){//Mid Square Hash Function
    long int x=value*value;
		   		cout <<x;
				if(x>99 && x <1000){
				cout <<"Key against the value is "<<(x / 10) % 10<<endl;
				return (x / 10) % 10 ;
				}else if(x>999 && x <100000){
					cout <<"Key against the value is "<<(x / 10) % 100 <<endl;
				return (x / 10) % 100 ;
				}else if(x>9999 && x <100000){
				cout <<"Key against the value is "<<(x / 10) % 100<<endl;
				return (x / 10) % 1000 ;
				}
    }
    void Insert(int key,int value){
        int index=HashFunc(value);
        if(T[index]!=NULL){
            delete T[index];
        }
        T[index]=new HashTableEntry(key,value);
    }
    int SearchKey(int key){
        if(T[key]==NULL){
            return -1;
        }else{
            return T[key]->value;
        }
    }
    void RemoveKey(int key){
        if(T[key]==NULL){
            cout << "No Element At key"<< key<<endl;
            return;
        }else{
            delete T[key];
        }
        cout << "Element Deleted"<< endl;
    }
     ~HashMapTable() {
         for (int i=0;i<Tablesize;i++) {
            if (T[i] != NULL){
               delete T[i];
            }
               delete[] T;
         }
      }
};

int main(){
    HashMapTable H;
    H.Insert(11,13);
    H.Insert(23,22);
    H.Insert(9,24);
    cout << H.SearchKey(6) << endl;
    cout << H.SearchKey(8) << endl;
    H.RemoveKey(8);
}