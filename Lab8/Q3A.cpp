//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 8 
//TASK 3 PART A
#include<iostream>
using namespace std;
class TreeNode{
public:
int value;
TreeNode *leftchild;
TreeNode *rightchild;
TreeNode(){
    value=0;
    leftchild=NULL;
    rightchild=NULL;
}
TreeNode(int value){
    this->value=value;
    leftchild=rightchild=NULL;
}
};
class BST{
public:
TreeNode *root;
BST(){
    root=NULL;
}
bool isTreeTrue(){
    if(root==NULL)
    return true;
    else
    return false;
}
void Insert(TreeNode* new_node){
if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> leftchild == NULL)) {
          temp -> leftchild = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> leftchild;
        } else if ((new_node -> value > temp -> value) && (temp -> rightchild == NULL)) {
          temp -> rightchild = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> rightchild;
        }
      }
    }
}
void PreOrder(TreeNode* root){
        if(!root)
        return;
    cout << root->value << " ";
    PreOrder(root->leftchild);
    PreOrder(root->rightchild);
}
void Inorder(TreeNode* root){
    if(!root)
        return;
    Inorder(root->leftchild);
    cout << root->value << " ";
    Inorder(root->rightchild);
}
};
int main(){
    BST obj;
    TreeNode *root = new TreeNode(50);
    obj.Insert(root);
    TreeNode *n1 = new TreeNode(20);
    obj.Insert(n1);
    TreeNode *n2 = new TreeNode(65);
    obj.Insert(n2);
    TreeNode *n3 = new TreeNode(54);
    obj.Insert(n3);
    cout << endl;
    obj.PreOrder(root);
    cout << endl;
}