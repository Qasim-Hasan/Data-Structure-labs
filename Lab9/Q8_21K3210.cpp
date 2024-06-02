//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 9
//QUESTION 8
//Balance factor of each node in a Binary tree
#include<iostream>
using namespace std;
class TreeNode {
  public:
  int value;
  int height;
  TreeNode * left;
  TreeNode * right;
  TreeNode() {
    value = 0;
    height=1;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};
class BinaryTree{
  public:
    TreeNode * root;
  BinaryTree() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      int lheight = height(r -> left);
      int rheight = height(r -> right);
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }
  void Insert(TreeNode *new_node){
    if(root==NULL){
        root=new_node;
    }else{
        TreeNode *temp=root;
        while(temp!=NULL){
            if(new_node->value==temp->value){
                cout << "Value Already Exist in tree";
                return;
            }else if(new_node->value<temp->value&&temp->left==NULL){
                temp->left=new_node;
                break;
            }else if(new_node->value<temp->value){
                temp=temp->left;
            }else if(new_node->value>temp->value&&temp->right==NULL){
                temp->right=new_node;
                break;
            }else{
                temp=temp->right;
            }
        }
    }
}
};

int main() {
  BinaryTree obj;
  TreeNode *root = new TreeNode(6);
obj.Insert(root);
 TreeNode *n1 = new TreeNode(3);
obj.Insert(n1);
 TreeNode *n2 = new TreeNode(9);
obj.Insert(n2);
TreeNode *n3 = new TreeNode(2);
obj.Insert(n3);
 TreeNode *n4 = new TreeNode(5);
obj.Insert(n4);
 TreeNode *n5 = new TreeNode(10);
obj.Insert(n5);
cout << endl;
cout <<"root:"<<obj.getBalanceFactor(root) << endl;
cout <<"n1:"<< obj.getBalanceFactor(n1) << endl;
cout <<"n2:"<<obj.getBalanceFactor(n2)<< endl;
cout <<"n3:"<< obj.getBalanceFactor(n3)<< endl;
cout <<"n4:"<<obj.getBalanceFactor(n4)<< endl;
cout <<"n5:"<<obj.getBalanceFactor(n5)<< endl;
}