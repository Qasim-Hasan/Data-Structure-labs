//Qasim Hasan
//Lab 11
//21K-3210
//BCS-3J
#include<iostream>
#define size 10
using namespace std;
class HashTableEntry{
    public:
        int key;
        string Value;
        HashTableEntry* Next;
        HashTableEntry(){
            Next = NULL;
        }
        HashTableEntry(int key, string Value){
            this->key= key;
            this->Value = Value;
            Next = NULL;
        }
};
class HashMapTable {
    private:
        HashTableEntry **T;
        int Count=0;
    public:
        HashMapTable(){
            T=new HashTableEntry*[size];
            for(int i=0;i<size;i++){
                T[i]=NULL;
            }
        }
        int HashFunc(int Key){
            return(Key%size);
        }
        bool HT_Empty(){
        if(Count == 0)
        return true;
        return false;
        }
        int BookSize(){
            return Count;
        }
        void Insert(int k, string v){
            int Index=HashFunc(k);
             Count++;
            HashTableEntry *New_E=new HashTableEntry(k,v);
            if(T[Index]==NULL){
                T[Index]=New_E;
                cout<<"Entry added"<<endl;
                return;
            }else{
                HashTableEntry* temp=T[Index];
                while(temp->Next!=NULL){
                    temp=temp->Next;
                }
                temp->Next=New_E;
            }
        }
        void PrintTable(){
        for(int i=0;i<size;i++){
            if(T[i]!=NULL){
            HashTableEntry* temp=T[i];
            while(temp!=NULL){
            cout<<temp->key<<"->"<<temp->Value<<endl;
            temp = temp->Next;
            }
            }
            }
        }
        int SearchKey(int k) {
            int index=HashFunc(k);
            HashTableEntry* temp=T[index];
            while(temp!=NULL){
            if(temp->key==k){
            return index;
            }
            temp=temp->Next;
            }
            return -1;
        }
        void Remove_Element(int k) {
            int index=SearchKey(k);
            if(index==-1){
            cout<<"Key doesnt exist"<<endl;
            return;
            }else{
            Count--;
            HashTableEntry* temp=T[index];
            if(temp->key==k){
            HashTableEntry* temp1 = T[index];
            T[index] = T[index]->Next;
            delete temp;
            temp = NULL;
            return;
            }else{
            while(temp->Next->key != k){
            temp = temp->Next;
            }
            HashTableEntry* temp1 = temp;
            temp->Next = temp->Next->Next;
            delete temp1;
            temp1 = NULL;
            return;
            }
            }
        }
        ~HashMapTable() {
        for(int i=0;i<size;i++){
            if(T[i]!=NULL){
            HashTableEntry* temp=T[i];
            while(temp!=NULL){
                HashTableEntry* temp1 = temp->Next;
                delete temp;
                temp = NULL;
                temp = temp1;
                }
            }
        }
        }
};

int main(){
    HashMapTable H;
    int id;
    string value;
    //Check Hash Table Empty of not
    if(H.HT_Empty())
        cout<<"Hash Table Empty"<<endl;
        else
        cout<<"Hash table Not Empty"<<endl;
    cout << "Enter Three Ids and Values"<< endl;
    //Enter Value
    for(int i=0;i<3;i++){
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter number: ";
        cin>>value;
        H.Insert(id,value);
    }
    //Print Table
    H.PrintTable();
    //Hah table after Insertion
    if(H.HT_Empty())
    cout<<"Hash Table Empty"<<endl;
    else
    cout<<"Hash table Not Empty"<<endl;
    //Contack book
    cout<<"\n Contact book Size: "<<H.BookSize();
    //Search pair
    cout<<"\n Search student ID: ";
    cin>>id;
    cout<<"\n Pair on Index: "<<H.SearchKey(id);
    //Delete Pair
    cout<<"\n Enter id for pair to be deleted: ";
    cin>>id;
    H.Remove_Element(id);
    //After Deletion
    cout<<"\n Size of contact book: "<<H.BookSize();
    //Print Table After Deletion
    H.PrintTable();
}