//LAB 5
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 4
#include<iostream>
using namespace std;
class Node{
public:
Node *next;
Node *prev;
int data;

Node(){
    next=prev=NULL;
}
Node(int data){
    this->data=data;
    next=NULL;
    prev=NULL;
}
};
class DoublyLinkList{
public:
Node *head;
Node *tail;
DoublyLinkList(){
    head=tail=NULL;
}

void AppendAtEnd(int data){
    Node *n=new Node(data);
    if(head==NULL){
        head=tail=n;
    }else{
      tail->next=n;
      n->prev=tail;
      tail=n;
    }
}

void displayDoubleLinkList(){
    if(head==NULL){
        cout << "\n Link List is Empty \n";
    }else{
        Node *temp=head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp=temp->next;        
        }
        cout << "NULL";
    }
    cout << endl;
}
void MergeDoublyLinkList(DoublyLinkList &L){
Node *temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=L.head;
L.head->prev=temp;
}
};

int main(){
DoublyLinkList L,M;
L.AppendAtEnd(87);
L.AppendAtEnd(12);
L.AppendAtEnd(65);
M.AppendAtEnd(34);
M.AppendAtEnd(23);
M.AppendAtEnd(19);
L.displayDoubleLinkList();
M.displayDoubleLinkList(); 

L.MergeDoublyLinkList(M);
L.displayDoubleLinkList();

}

