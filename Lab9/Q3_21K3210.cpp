//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 3
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
    bool checkOp(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
		return true;
	}else{
		return false;
	}
}
int precedence(char c) { 
    if(c=='^') 
    return 3; 
    else if(c=='*'||c== '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}
int gettop(){
    return arr[top];
}
string InfixToPostfix(Stack s, string infix){
	string postfix;
	for(int i=0;i<infix.length();i++){
		if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z')){
			postfix+=infix[i];
		}else if(infix[i] == '('){
			s.push(infix[i]);
		}else if(infix[i] == ')'){
			while((s.gettop()!='(') && (!s.StackEmpty())){
				char temp=s.gettop();
				postfix+=temp;
				s.Pop();
			}
			if(s.gettop()=='('){
				s.Pop();
			}
		}else if(checkOp(infix[i])){
			if(s.StackEmpty()){
				s.push(infix[i]);
			}else{
				if(precedence(infix[i])>precedence(s.gettop())){
					s.push(infix[i]);
				}else if((precedence(infix[i])==precedence(s.gettop()))&&(infix[i]=='^')){
					s.push(infix[i]);
				}else{
					while((!s.StackEmpty())&&( precedence(infix[i])<=precedence(s.gettop()))){
						postfix+=s.gettop();
						s.Pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.StackEmpty()){
		postfix+=s.gettop();
		s.Pop();
	}
	return postfix;
} 
};
int main(){
    Stack s1;
  	string exp="a+b*(c^d-e)^(f+g*h)-i";
    string postfix;
	cout<<"Infix: "<<exp;
  	postfix=s1.InfixToPostfix(s1,exp);
    cout<<"\nPostfix: "<<postfix;
}