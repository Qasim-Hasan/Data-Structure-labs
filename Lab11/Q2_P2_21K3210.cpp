//Qasim Hasan
//Lab 11
//21K-3210
//BCS-3J
//QUESTION 2 PART 2

//HASH FUNCTION (DIVISION)

#include<iostream>
using namespace std;
const int Tablesize =100;

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
    int HashFunc(int key){
        return key%Tablesize;
    }
    void Insert(int key,int value){
        int index=HashFunc(key);
        while(T[index]!=NULL&& T[index]->key!=key){
            index=HashFunc(index+1);
        }
        if(T[index]!=NULL){
            delete T[index];
        }
        T[index]=new HashTableEntry(key,value);
    }
    int SearchKey(int key){
        int index=HashFunc(key);
        while(T[index]!=NULL&&T[index]->key!=key){
        index=HashFunc(index+1);
        }
        if(T[index]->key!=key){
            return -1;
        }else{
            return T[index]->value;
        }
    }
    void RemoveKey(int key){
        int index=HashFunc(key);
        while(T[index]!=NULL){
            if(T[index]->key==key){
                break;
            }
            index=HashFunc(index+1);
        }
        if(T[index]==NULL){
            cout << "No Element At key"<< key<<endl;
        }else{
            delete T[index];
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
    H.Insert(11,2);
    H.Insert(23,22);
    H.Insert(9,24);
    cout << H.SearchKey(9) << endl;
    cout << H.SearchKey(11) << endl;
    H.RemoveKey(9);
}