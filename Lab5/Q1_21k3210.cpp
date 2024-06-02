//LAB 5
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 1
#include<iostream>
using namespace std;

class Node{
public:
Node *next;
Node *previous;
int Data;

Node(int Data){
    this->Data=Data;
    next=NULL;
    previous=NULL;
}
Node(){
    next=NULL;
    previous=NULL;
}
};

class EntireDoublyLinkList{
Node *head;
Node *tail;
public:
EntireDoublyLinkList(){
    head=NULL;
    tail=NULL;
}
//Delete the First Node
void deleteFirstNode(){
    if(head==NULL){
    cout << "empty" << endl;
    }
    else{
    if(head==tail){
        delete head;
        head = tail = NULL;
    }
    else{
        Node *temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
        }
      }
    }
//Delete the End Node
void deleteLastNode(){
    if(head==NULL){
        cout << "List is empty" << endl;
    }
    else{
    if (head==tail){
        delete head;
        head = tail = NULL;
    }
    else{
        Node *temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete temp;
       }
     }
    }

//Deleting A node At ANY Position
void delete_Node(int Id_of_Node){
    if(Id_of_Node==0){
        deleteFirstNode();
    }else{
        int count_of_node=0;
        Node *temp=head;
        Node *prev=NULL;
        while(count_of_node!=Id_of_Node && temp!=NULL){
            prev=temp;
            temp=temp->next;
            count_of_node++;
        }
        if(temp!=NULL){
             if(temp->next==NULL){
                deleteLastNode();
             }else{
                prev->next=temp->next;
                temp->next->previous=prev;
                delete temp;
             }
        }else{
            cout << "Invalid Position entered\n";
        }
    }
}
//Printing the Link List By traiversing
void PrintingtheDoublyLinkList(){
    if(head==NULL){
        cout << "\n Link List is Empty.\n";
    }else{
        Node *temp=head;
        while(temp!=NULL){
            cout << temp->Data << " ";
            temp=temp->next;
        }
        cout << "NULL" << endl;
    }
}
//Append Function To give Data At the End of the Link List
void AppendAtEnd(int data){
    Node *new_node=new Node(data);
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }else{
        tail->next=new_node;
        new_node->previous=tail;
        tail=new_node;
    }
}
//Prepend Function To give Data At the start of the List
void PrependAtStart(int data){
    Node *new_node=new Node(data);
    if(head==NULL){
    head=new_node;
    tail=new_node;
    }else{
    new_node->next=head;
    head->previous=new_node;
    head=new_node;
    }
}
//Inserting Data at any position
void InsertAnyPosition(int Id_of_Node,int data){
    Node *new_node=new Node(data);
    if(Id_of_Node==0){
    PrependAtStart(data);
    }else{
        Node *temp=head;
        Node *prev=NULL;
        int count_of_Node=0;
        while(count_of_Node != Id_of_Node && temp !=NULL){
            prev=temp;
            temp=temp->next;
            count_of_Node++;
        }
        if(temp!=NULL){
            new_node->next=temp;
            temp->previous=new_node;
            prev->next=new_node;
            new_node->previous=prev;
        }else{
            cout << "Invalid Position entered \n";
        }
    }
}

};
int main(){
    EntireDoublyLinkList D1;
    int optionforswitch=0;
    cout << "\n DOUBLY LINK LIST \n";
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
            D1.InsertAnyPosition(Id,data3);
            break;
            case 4:
            int Id1;
            cout << "Enter The Node Position You want to delete: ";
            cin >> Id1;
            D1.delete_Node(Id1);
            break;
            case 5:
            D1.PrintingtheDoublyLinkList();
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