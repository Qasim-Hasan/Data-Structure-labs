//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 8 
//TASK 2 PART A
#include<iostream>
using namespace std;
class treenode{
public:
int data;
treenode *leftchild;
treenode *rightchild;
treenode(int data){
    this->data=data;
    leftchild=rightchild=NULL;
}
};
class BinaryTree{
public:
treenode *root;
BinaryTree(){
    root=NULL;
}
bool EmptyTree(){
    if(root==NULL)
    return true;
    else
    return false;
}
void Insert(treenode *new_node){
    if(root==NULL){
        root=new_node;
    }else{
        treenode *temp=root;
        while(temp!=NULL){
            if(new_node->data==temp->data){
                cout << "Value Already Exist in tree";
                return;
            }else if(new_node->data<temp->data&&temp->leftchild==NULL){
                temp->leftchild=new_node;
                break;
            }else if(new_node->data<temp->data){
                temp=temp->leftchild;
            }else if(new_node->data>temp->data&&temp->rightchild==NULL){
                temp->rightchild=new_node;
                break;
            }else{
                temp=temp->rightchild;
            }
        }
    }
}
  void Inorder(treenode* root){
    if(!root)
        return;
    Inorder(root->leftchild);
    cout << root->data << " ";
    Inorder(root->rightchild);
}
};
int main(){
BinaryTree obj;
 treenode *root = new treenode(50);
obj.Insert(root);
 treenode *n1 = new treenode(23);
obj.Insert(n1);
 treenode *n2 = new treenode(16);
obj.Insert(n2);
 treenode *n3 = new treenode(65);
obj.Insert(n3);
 treenode *n4 = new treenode(57);
obj.Insert(n4);
obj.Inorder(root);
     cout << endl;
}