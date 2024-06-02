//LAB 9
//Qasim Hasan
//21K-3210
//BCS-3J
//QUESTION 5
#include<iostream>
using namespace std;
class TreeNode{
	public:
		TreeNode* next;
		int data;
		TreeNode(int data){
			this->data = data;
			next = NULL;
		}
};
class EntireQueueUsingLinkList{
	public:
		TreeNode *front;
        TreeNode *rear;
		EntireQueueUsingLinkList(){
			front =NULL;
            rear = NULL;
		}
		void ADDMEMEBER(int data){
			TreeNode* new_node = new TreeNode(data);
			if(EmptyQueue()){
				front = rear = new_node;
			}
			else{
				rear->next = new_node;
				rear = new_node;
			}
		}
		void REMOVEMEMEBER(){
			if(EmptyQueue()){
                cout << "Queue is empty\n";
			}
			else{
                TreeNode* temp = front;
				front = front->next;
				delete temp;
			}
		}
		bool EmptyQueue(){
            if(front==0){
                return true;
            }else{
                return false;
            }
		}
		void print(){
			if(EmptyQueue()){
				cout << "\n Queue is empty\n";
			}else{
            	TreeNode* temp = front; //head
                cout << "\n Queue Elements:";
				while(temp!=NULL)
				{
					cout << temp->data << " ";
					temp = temp->next;
				}
				cout << "NULL";	
            }
		}
};
int main(){
	EntireQueueUsingLinkList q;
    q.ADDMEMEBER(21);
    q.ADDMEMEBER(98);
    q.ADDMEMEBER(368);
    q.print();

    q.REMOVEMEMEBER();
    q.REMOVEMEMEBER();
    q.print();
    q.REMOVEMEMEBER();
    q.print();
}