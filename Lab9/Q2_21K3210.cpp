//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 2
#include<iostream>
using namespace std;
class TreeNode{
public:
int data;
TreeNode *next;
TreeNode(){}
TreeNode(int data){
    this->data=data;
    next=NULL;
}
};
class Stack{
public:
TreeNode *top;
Stack(){
    top=NULL;
}
void Push(int data){
    TreeNode *temp;
    temp=new TreeNode;
    temp->data=data;
    temp->next=top;
    top=temp;
}
bool isempty(){
 return(top==NULL);
}
void Pop(){
    if(isempty()){
        cout << "Stack Empty";
    }else{
        TreeNode *temp=top;
        top=top->next;
        delete temp;
    }
}
int Peek(){
    if(isempty()){
     cout << "Stack Empty";
    }else{
    cout << "\n Top  Value: "<< top->data;
}
}

void PrintReverse(TreeNode *top){
if (top == NULL)
    return;
    PrintReverse(top->next);
    cout << top->data << " ";
}

void displayStack(){
 if (isempty()){
 cout<<"Stack is Empty";
 }else{
  TreeNode *temp=top;
  while(temp!=NULL){
       cout<< temp->data << " ";
       temp=temp->next;
  }
  cout<<"\n";
 }
 }
};


int main(){
Stack s1;
s1.Push(1);
s1.Push(2);
s1.Push(3);
s1.Push(21);
s1.Push(12);
s1.Peek();
cout << endl;
s1.displayStack();
s1.Pop();
s1.Pop();
s1.displayStack();
s1.PrintReverse(s1.top);
}