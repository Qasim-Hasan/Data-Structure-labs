//Qasim Hasan
//Lab 11
//21K-3210
//BCS-3J
//QUESTION 3
#include<iostream>
#define size 10
using namespace std;
class HashTableEntry{
    public:
        int key;
        string value;
        HashTableEntry(){}
        HashTableEntry(int key, string value) {
        this->key= key;
        this->value = value;
        }
};
class HashMapTable{
    private:
        HashTableEntry **T;
        int Count=0;
    public:
    HashMapTable(){
        T=new HashTableEntry*[size];
            for(int i=0;i<size;i++){
                T[i] = NULL;
            }
        }
    int HashFunc(int key){
        return(key%size);
        }
    bool HT_Empty(){
        if(Count==0)
        return true;
        return false;
        }
    void PrintTable(){
        for(int i=0;i<size;i++){
        if(T[i] != NULL){
        cout<<T[i]->key<<"->"<<T[i]->value<<endl;
        }
        }
        }    
    void Insert(int key,string value){
        int index = HashFunc(key);
        HashTableEntry *newEntry = new HashTableEntry(key,value);
        if(Count>=10){
            cout<<"Hash Table is FULL"<<endl;
            return;
        }
        Count++;
        if(T[index] == NULL){
            T[index] = newEntry;
            cout<<"Entry has been added"<<endl;
            return;
        }
        for(int i=0;i<size;i++){
            if(T[index%size] != NULL){
            index++;
            continue;
            }else{
            T[index%size] = newEntry;
            cout<<"Entry added. "<<endl;
            return;
            }
        }
    }
    int BookSize(){
        return Count;
    }
    int SearchKey(int key) {
        int index=HashFunc(key);
        for(int i=0;i<size;i++){
        if(T[index%size]->key==key){
        return index%size;
        }else{
        index++;
        }
        }
    return -1;
    }
    void Remove_Element(int key) {
    int index=SearchKey(key);
        if(index==-1){
        cout<<"Key doesnt exist"<<endl;
        return ;
        }
        Count--;
        delete T[index];
        T[index]=NULL;
    }
    ~HashMapTable() {
    delete []T;
    T=NULL;
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