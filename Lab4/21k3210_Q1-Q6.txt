//  SINGLE LINKED LIST
//  Qasim hasan
//  21k-3210
//  BCS-3J
// QUESTION 1 TILL QUESTION 5 

//QUESTION 1: Implement a SinglyLinkedList class
#include<iostream>
using namespace std;
class Node{
	public:
		string name;
		int age,studentId;
		Node *next;
    Node(){
    	name="NULL";
    	age=0;
    	studentId=0;
    	next=NULL;
	}
	Node(int name,int age,int studentId ){
		this->name=name;
		this->age=age;
		this->studentId=studentId;
	}
};
class SinglyLinkedList{
	public:
	Node *head;
	SinglyLinkedList(){
	head=NULL;
	}
	SinglyLinkedList(Node *n){
	head=n;
	}
	//  check if the node exist
    Node * nodeExist(int Id) {
    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> studentId == Id) {
        return ptr;
      }
      ptr = ptr -> next;
     }
     return NULL;
    }
    //QUESTION 2 Add a node at the end
	//	Append (End of the list)
    void appendNode(Node *n){
    	if(nodeExist(n->studentId)!=NULL){
    		cout << "Node exist.";
		}else{
			if (head==NULL){
				head = n;
				cout << "Node has been added ";
			}else{
				Node *ptr =head;
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=n;
				cout << "Node has been added";
			}
		}
	}
    //QUESTION 3 Add a node at the front
    //  Prepend (Start of the list)}
    void prependnode(Node *n){
		if(nodeExist(n->studentId)!=NULL){
			cout <<" Node exist ";
		}else{
			if(head==NULL){
				head=n;
				cout << "Node has been added";
			}else{
				n->next=head;
				head=n;
				cout << "Node has been added";
			}
		}
	}
    //QUESTION 4 4 Add a node after a given node
    //  Insert a Node after a particular node in the list
     void Insertion(int ID,Node *n){
      Node *ptr = nodeExist(ID);
	  if(ptr==NULL){
		cout << "Cannot insert no node available with given studentID\n";
	  }else{
		if(nodeExist(n->studentId)!=NULL){
			cout << "The studentid/node already exist";
			cout << "\n Enter a Id which do not exist in the list to store new data \n";
		}else{
			n->next=ptr->next;
			ptr->next=n;
			cout << " Node Inserted ";
		}
	  }
	 }
    //QUESTION 5 Delete Last Node
    void Deletion(int ID){
         if(head==NULL){
			cout << "No Node Available to delete";
		 }else if(head!=NULL){
             if(head->studentId==ID){
                head=head->next;
				cout <<"Node deleted";
			 }else{
				Node *temp=NULL;
				Node *prevptr=head;
				Node *currptr=head->next;
				     while(currptr!=NULL){
						if(currptr->studentId==ID){
						    temp=currptr;
						    currptr=NULL;
					        }else{
								prevptr=prevptr->next;
								currptr=currptr->next;
							}  
			        }
				if(temp!=NULL){
					prevptr->next=temp->next;
					cout << "Node unlinked with keys values";
				}else{
					cout << "Node doesn't exist with key values";
				}
			 }
		 }
	}
    //QUESTION 6 Update a Node
    void Updation(int ID,string name,int age){
    Node *ptr = nodeExist(ID);
	if(ptr!=NULL){
		ptr->name=name;
		ptr->age=age;
		cout << "Student Data Updated";
	}else{
		cout << "Student Id does not exist";
	}
	}
    //Printing the Link List 
	void printlist(){
		if(head==NULL){
			cout << " No Nodes in linked list";
		}else{
			cout << " Linked List(StudentID->Name->Age): ";
			Node *temp =head;
			while(temp!=NULL){
				cout << "("<<temp->studentId<<"->"<< temp->name<<"->"<< temp->age<<")";
				temp=temp->next;
			}
		}
	}
};
int main(){
	SinglyLinkedList s1;
	int choice,Id;
	string name;
	int age, studentId;
	cout << "\n      STUDENT INFORMATION DETAILS      \n";
	cout << " 1. APPEND (Add a node at the end) \n";
	cout << " 2. PREPEND (Add a node at the start) \n";
	cout << " 3. INSERTION (Add a node at particular position)\n";
	cout << " 4. DELETE (Delete a node from any position)\n";
	cout << " 5. UPDATE (Update a node at particular poistion)\n";
	cout << " 6. DISPLAY (Print the linked list\n";
	cout << " 0. EXIT PROGRAM \n";
	do{
	cout << "\n Enter Choice: ";
	cin >> choice;
	Node *n =new Node();
	switch(choice){
     	case 1:
			cout << "Now Appending at the end :\n";
			cout << "Enter Student Name: ";
			fflush(stdin);
			getline(cin,name);
			cout << "Enter Student Id: ";
			cin  >> studentId;
			cout << "Enter Student Age: ";
			cin >> age;
			n->name=name;
			n->studentId=studentId;
			n->age=age;
			s1.appendNode(n);
			break;
		case 2:
		 	cout << "Now Prepending at the start :\n";
			cout << "Enter Student Name: ";
			fflush(stdin);
			getline(cin,name);
			cout << "Enter Student Id: ";
			cin  >> studentId;
			cout << "Enter Student Age: ";
			cin >> age;
			n->name=name;
			n->studentId=studentId;
			n->age=age;
			s1.prependnode(n);
			break;
		case 3:
			cout << "Now Inserting at the any position :\n";
			cout << "Enter the Student Id after which you want add the new node:\n";
			cin >> Id;
			cout <<" Enter data of new student/node:\n";
			cout << "Enter Student Name: ";
			fflush(stdin);
			getline(cin,name);
			cout << "Enter Student Id: ";
			cin  >> studentId;
			cout << "Enter Student Age: ";
			cin >> age;
			n->name=name;
			n->studentId=studentId;
			n->age=age;
			s1.Insertion(Id,n);
			break;
		case 4:
			cout << " Delete node by giving student Id ";
			cin >> studentId;
			s1.Deletion(studentId);
			break;
		case 5:
            cout << " Update node by giving student Id ";
			cin >> Id;
			cout << "New Name:";
			fflush(stdin);
			getline(cin,name);
			cout << "New Age: ";
			cin >> age;
		    s1.Updation(Id,name,age);
			break;	
		case 6:
		    s1.printlist();	
			break;	
	}
}while(choice!=0); 
cout <<"\nPROGRAM ENDED";
return 0;
}
