//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 1
#include<iostream>
using namespace std;
#define size 10
class Stack {
    public:
    int top;
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
    bool Pop(){
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
        cout << "\n The Stack Created :";
        for(int i=top;i>=0;i--){ 
            cout << " " << arr[i];
        }
    }
};

int main(){
Stack s1;
cout <<  endl;
s1.push(8);
s1.push(4);
s1.push(32);
s1.push(64);
s1.push(11);
s1.push(32);
s1.push(44);
s1.push(23);
s1.push(311);
s1.push(6431);//10th value
s1.print();
s1.push(23);//Overflow
cout << endl;
cout << " At peek:" <<s1.peek(); //The toppest value
for(int i=0;i<size;i++){
    s1.Pop();
}
s1.Pop();//underflow empty
}