//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 8 
//TASK 2 PART B
#include<iostream>
using namespace std;
class TreeNode{
public:
TreeNode *rightchild;
TreeNode *leftchild;
int data;
TreeNode(int data){
    this->data=data;
    rightchild=leftchild=NULL;
}
TreeNode(){
    data=0;
    rightchild=leftchild=NULL;
}
};
class BST{
public:
TreeNode *root;
BST(){
    root=NULL;
}
void Insert(TreeNode *new_node){
    if(root==NULL){
        root=new_node;
    }else{
        TreeNode *temp=root;
        while(temp!=NULL){
        if(temp->data==new_node->data){
            cout << "Data Already Exist in tree";
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
void Inorder(TreeNode *root){
    if(!root)
    return;
    Inorder(root->leftchild);
    cout << root->data << " ";
    Inorder(root->rightchild);
}
};
int main(){
BST s;
int data[]={15,10,20,8,12,16,25};
int n=sizeof(data)/sizeof(data[0]);
for(int i=0;i<n;i++){
TreeNode *root=new TreeNode(data[i]);
s.Insert(root);
}
cout << endl;
s.Inorder(s.root);
}
