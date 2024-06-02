//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 7
#include<iostream>
#include <string>
using namespace std;
#define size 10
class Stack {
    public:
    int top;
    char arr[size];  //char array
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
    char gettop(){
    return arr[top];
    }
    void  CompareBracket(string s){
    Stack s2;
    int l = s.length();
    char top;
    for(int i=0;i<l;i++){
        top=s2.gettop();
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
     s2.push(s[i]);
    }else{
      top=s2.gettop();
      if(s[i]==')'&&top=='('||s[i]=='}'&&top=='{'||s[i]==']'&&top=='[') {
        s2.Pop();
      }else{
        cout<<" Invalid parentheses " << s <<endl;
        return;
      }
     }
    }
    if(s2.StackEmpty()){
       cout<<" Valid parentheses  " <<s <<endl;
    }else{
       cout<<" Invalid parentheses  "<<s <<endl;
    }
}
};

int main(){
 Stack s1;
 string string1 = "({{[]}})";
 string string2 = "{]}";
 s1.CompareBracket(string1);
 s1.CompareBracket(string2);
}