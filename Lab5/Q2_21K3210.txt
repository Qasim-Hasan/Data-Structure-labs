//LAB 5
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 2
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int data){
    this->data=data;
    next=NULL;
}
Node(){
    next=NULL;
}
};

class EntireCircularLinkList{
public:
Node *tail;
EntireCircularLinkList(){
    tail=NULL;
}
//printing the Link List By traiversing
void printLinkList(){
    if(tail==NULL){
        cout << "Link List Is Empty ";
    }else{
        Node *temp = tail->next;//head
        do{
        cout << temp->data << " ";
        temp=temp->next;
        }while(temp!=tail->next);
    }
}
//Add A NODE At the Start of the Link List
void PrependAtStart(int data){
    Node *new_node=new Node(data);
    if(tail==NULL){
        tail=new_node;
        tail->next=new_node;//head
    }else{
        new_node->next=tail->next;
        tail->next=new_node;
    }
}
//Add A NODE At the End of the Link List
void AppendAtEnd(int data){
    Node *new_node=new Node(data);
    if(tail==NULL){
        tail=new_node;
        tail->next=new_node;
    }else{
        new_node->next=tail->next;
        tail->next=new_node;
        tail=new_node;
    }
}
//Insert At Any Position of the Link List
void InsertAtNode(int Id_of_node,int data){
    if(Id_of_node==0){
        PrependAtStart(data);
    }else{
    Node *temp=tail->next;
    Node *previous=NULL;
    int count_Node=0;
    do{
    previous=temp;
    temp=temp->next;
    count_Node++;
    }while(temp!=tail->next && count_Node != Id_of_node-1);

    if(temp==tail && count_Node==Id_of_node){
        AppendAtEnd(data);
    }else{
        Node *new_node=new Node(data);
        new_node->next=temp->next;
        temp->next=new_node;
    }
    }
}
//Delete Node AT ANY Position in the link list
void delete_Node(int Id_of_Node){
   if(tail==NULL){
    cout << "Link list does not exist";
    }else{
    if(Id_of_Node==0){
        deleteFirstNode();
    }else{
      Node *temp=tail->next;
      Node *previous=NULL;
      int count=0;
      do{
      previous=temp;
      temp=temp->next;
      count++;
      }while(temp!=tail->next && count < Id_of_Node);
        if(Id_of_Node==count && temp==tail){
            deletelastnode();
        }else{
            previous->next=temp->next;
            delete temp;
        }
    }
}
}
//Delete the Start Node from the link List
void deleteFirstNode(){
    if(tail==NULL){
        cout << " list is empty ";
    }else{
        if(tail->next==tail){
            delete tail;
            tail=NULL;
        }else{
            Node *temp=tail->next;
            tail->next=temp->next;
            delete temp;
        }
    }
}
//Delete the last Node from the link List
void deletelastnode(){
    if(tail==NULL){
        cout << "List does not exist";
    }else{
        if(tail->next==tail){
            delete tail;
            tail=NULL;
        }else{
             Node *temp=tail->next;
             Node *prev=NULL;
             do{
                prev=temp;
                temp=temp->next;
             }while(temp!=tail);
             prev->next=tail->next;
             tail=prev;
             delete temp;
        }
    }
}
};
int main(){
EntireCircularLinkList D1;
    int optionforswitch=0;
    cout << "\n CIRCULAR LINK LIST \n";
    cout << "1. Appending at the End of the List \n";
    cout << "2. Prepending at the start of the List \n";
    cout << "3. Insert at Any given Node Position \n";
    cout << "4. Deleting at Any given Node Position \n";
    cout << "5. Printing the Link List \n";
    cout << "6. Exit the Program\n";
    do{
    cout << "ENTER OPTION (1-6): ";
    cin >> optionforswitch;

    switch(optionforswitch){
            case 1:
            int data1;
            cout << "Enter Data: ";
            cin >> data1;
            D1.AppendAtEnd(data1);
            break;
            case 2:
            int data2;
            cout << "Enter Data: ";
            cin >> data2;
            D1.PrependAtStart(data2);
            break;
            case 3:
            int Id,data3;
            cout << "Enter the Position Number:";
            cin >> Id;
            cout << "Enter Data:";
            cin >> data3;
            D1.InsertAtNode(Id,data3);
            break;
            case 4:
            int Id1;
            cout << "Enter The Node Position You want to delete: ";
            cin >> Id1;
            D1.delete_Node(Id1);
            break;
            case 5:
            D1.printLinkList();
            cout << endl;
            break;
            case 6:
            cout << "Program Ended";
            exit(0);
            break;
            default:
            cout << "Enter the Correct Option \n";
            break;
    }
    }while(optionforswitch!=6);
}