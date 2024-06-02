//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 9
//QUESTION 10
//find whether if a given binary tree is binary search tree and AVL tree?
#include<iostream>
#include<stdlib.h>
#include <cstdlib>
using namespace std;
class TreeNode{
  public:
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(){}
  TreeNode(int data){
    this->data = data;
    left =right =NULL;
  }
};
class BST{
  public:
  TreeNode* root;
  BST(){
    root  =NULL;
}
   bool IsEmpty(){
    if (root == NULL){
        return true;
    }else{
        return false;
    }
    }
   void InsertNode(int data){
     TreeNode *new_node = new TreeNode(data);
     TreeNode *temp = root;
       TreeNode *t;
     if (root == NULL){
        new_node->left = new_node->right = NULL;
        root = new_node;
        return;
     }
     while (temp!=NULL){
        t = temp;
        if (data < temp->data){
            temp= temp->left;
        }
        else if (data > temp->data){
            temp= temp->right;
        }else{
            cout<<"No Duplicates"<<endl;
        }          
     }
      if(data< t->data){
         t->left = new_node;
      }else{
         t->right = new_node;
      }
   } 
   int GetHeight(TreeNode *root){
      if (root== NULL){
        return 0;
      }
      else{
        int lheight=GetHeight(root->left);
        int rheight =GetHeight(root->right);
        if (lheight>rheight){
            return (lheight+1);
        }else{
            return (rheight+1);
        }
      }
   }
    void GetLevel(TreeNode* r){
     int h = GetHeight(root);
     for (int i = 0; i < h; i++){
       Print(root,i);
       cout<<endl;
     }
   }
   TreeNode* IsSorted(int arr[],int low,int end){
      int mid = (low+end)/2;
      if (low > end){
         return NULL;
      }
      root = new TreeNode(arr[mid]);
      root->left = IsSorted( arr,low,mid-1);
      root->right = IsSorted( arr,mid+1,end);
      return root;
   }
   void Print(TreeNode *root, int l){
         if (root==NULL){
            return ;
         }
         if (l == 1){
            cout<< root->data<<" ";
         }else{
            Print(root->left,l-1);
            Print(root->right,l -1);
         }
   }
   bool isBST(TreeNode * root,TreeNode* min=NULL,TreeNode * max=NULL){
     if (root == NULL){
      return true;
     }
     if (min != NULL && root->data <= min->data){
      return false;
     }
      if (max != NULL && root->data >= max->data){
      return false;
     }
     bool left = isBST(root->left,min,root);
     bool right = isBST(root->right,root,max);
     return left && right;
   }
   bool isBalanced(TreeNode *root){
        if (root==NULL){
            return true;
        }
        if (isBalanced(root->left)== false){
            return false;
        }
        if(isBalanced(root->right)==false){
            return false;
        }
        int LeftHeight =GetHeight(root->left);
        int rightHeight = GetHeight(root->right);
        if (abs(LeftHeight-rightHeight)<=1){
            return true;
        }else{
            return false;
        }
   }
};
   int main(){
   BST s1;
   s1.InsertNode(100);
   s1.InsertNode(50);
   s1.InsertNode(150);
   s1.InsertNode(25);
   s1.InsertNode(75);
   s1.InsertNode(125);
   s1.InsertNode(175);
   s1.InsertNode(65);
   s1.InsertNode(85);
   s1.GetLevel(s1.root);
    if(s1.isBST(s1.root,NULL,NULL)){
     if (s1.isBalanced(s1.root)){
        cout<<"\n Tree is both balanced and BST"<<endl;
     }else{
        cout<<" Binary Search Tree Only "<<endl;
     }}else{
        cout<<"Nor AVL or BST"<<endl;
    }
}