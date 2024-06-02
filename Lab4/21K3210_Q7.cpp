//  SINGLE LINKED LIST
//  Qasim hasan
//  21k-3210
//  BCS-3J
//  QUESTION 7
#include<iostream>
using namespace std;
class Node{
	public:
		int number; 
        Node *next;
    Node(){
    	next=NULL;
	}
	Node(int number,Node *n=NULL){
		this->number=number;
        next=n;
	}
};
class SinglyLinkedList{
	public:
	Node *head,*tail;
	SinglyLinkedList(){
	head=tail=NULL;
	}
	SinglyLinkedList(Node *n){
	head=n;
	}
       bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void addToTail(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void Deletion(int ID){
         if(head==NULL){
			cout << "No Node Available to delete";
		 }else if(head!=NULL){
             if(head->number==ID){
                head=head->next;
			 }else{
				Node *temp=NULL;
				Node *prevptr=head;
				Node *currptr=head->next;
				     while(currptr!=NULL){
						if(currptr->number==ID){
						    temp=currptr;
						    currptr=NULL;
					        }else{
								prevptr=prevptr->next;
								currptr=currptr->next;
							}  
			        }
				if(temp!=NULL){
					prevptr->next=temp->next;
				}else{
				}
			 }
		 }
	}
	//QUESTION 7 
    void sort(){
        int i=0;
    if(head==NULL){
        cout << "linked list is empty cannot sort data";
    }else{
        Node *ptr = head;
        while(ptr->next!=NULL){
            if(ptr->number%2==0){
            }else{
                if(i<5){
             addToTail(ptr->number);
             Deletion(ptr->number);
             i++;
                }
            }
            ptr=ptr->next;
    }
    cout << "LINK LIST SORTED\n";
    printlist();
    }
    }
    //Printing the Link List 
void printlist(){
	if (isEmpty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->number<< "   ";
                temp = temp->next;
            }
            cout << endl;
        }
	}
};
int main(){
	SinglyLinkedList s1;
	int choice,number;
    s1.addToTail(17);
    s1.addToTail(15);
    s1.addToTail(8);
    s1.addToTail(12);
    s1.addToTail(10);
    s1.addToTail(5);
    s1.addToTail(4);
    s1.addToTail(1);
    s1.addToTail(7);
    s1.addToTail(6);
	cout << "\n 1. DISPLAY (Print the linked list)\n";
	cout << " 2. SORT (Sort the given the linked list to even and odd data)\n";
	cout << " 0. EXIT PROGRAM \n";
	do{
	cout << "\n Enter Choice: ";
	cin >> choice;
	switch(choice){
		case 1:
		    s1.printlist();	
			break;
		case 2:
            s1.sort();
			break;	
	}
}while(choice!=0); 
cout <<"\nPROGRAM ENDED";
return 0;
}
