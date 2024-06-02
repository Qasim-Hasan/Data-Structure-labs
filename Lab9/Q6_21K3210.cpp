//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 6
#include<iostream>
using namespace std;
#define size 10
class Stack {
    public:
    int top;
    static int count;
    int arr[size]; 
    Stack(){
    top = -1; 
    }
    bool StackFull(){      
    if(top>=(size-1)){
    return 1;
    }else{
    return 0;
    }
    }
    int peek(){
        if(StackEmpty()){
            cout << "Stack Empty";
            return 0;
        }else{
            int temp=arr[top];
            return temp;
        }
    }
    int Pop(){
        if(StackEmpty()){
            cout << "\n Stack Empty";            
        return 0;
        }else{
            int temp=arr[top];
            --top;
        return temp;
        }
    }
    bool StackEmpty(){  
     if(top==-1){
        return 1;
     }   else{
        return 0;
     }
    }
    bool push(int data){
    if(StackFull()){
        cout << "\n Stack is Full cannot Overflow";
        return false;
    }else{
        arr[++top]=data;
        return true;
    }
    }
    void print(){
        for(int i=top;i>=0;i--){ 
            cout << " " << arr[i];
        }
    }
    Stack undo(Stack &s2){
    int val=Pop();
    s2.push(val);
    }
    Stack redo(Stack &s2){
    int val=s2.Pop();
    push(val);    
    }
};
int main(){
Stack s1,s2;
s1.push(98);
s1.push(76);
s1.push(657);
cout << "3 values Pushed:";
s1.print();//657 76 98
cout << endl;
s1.undo(s2);  
cout << "1st Undo:"; 
s1.print();    //  76 98 print after undo
cout << endl;
cout << "2nd Undo:"; 
s1.undo(s2);   
s1.print();    // 98 print after undos
cout << endl;
cout << "3rd Undo:"; 
s1.undo(s2);   
cout << " Stack Empty";
s1.print();   // empty
cout << endl;
cout << "1st Redo:"; 
s1.redo(s2);   // redo to remove the value
s1.print();
cout << endl;
cout << "2nd Redo:"; 
s1.redo(s2);   
s1.print();
cout << endl;
cout << "3rd Redo:"; 
s1.redo(s2);   
s1.print();  
}