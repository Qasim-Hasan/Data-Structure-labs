//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 9
//QUESTION 11
//given a sorted array, convert it into a balanced binary search tree or AVL tree.
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
    int GetHeight(TreeNode *root){
      if (root== NULL){
        return 0;
      }else{
        int lheight=GetHeight(root->left);
        int rheight =GetHeight(root->right);
        if (lheight>rheight){
            return lheight+1;
        }else{
            return rheight+1;
        }    
      }
   }
   void Print(TreeNode * r, int level){
         if (r==NULL){
            return ;
         }
         if (level == 1){
            cout<< r->data<<" ";
         }else{
            Print(r->left,level-1);
            Print(r->right,level -1);
         }     
   }
   void GetLevel(TreeNode* root){
     int height = GetHeight(root);
     for (int i = 0; i < height; i++){
       Print(root,i);
       cout<<endl;
    }
   }
   TreeNode* IsSorted(int arr[],int low,int end){
	if (low> end)
	return NULL;
	int mid = (low + end)/2;
	TreeNode *root = new TreeNode(arr[mid]);
	root->left = IsSorted(arr, low,mid - 1);
	root->right = IsSorted(arr, mid + 1, end);
	return root;
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
        int leftHeight =GetHeight(root->left);
        int RightHeight = GetHeight(root->right);
        if (abs(leftHeight-RightHeight)<=1){
            return true;
        }
        else{
            return false;
        }
   }
   void PrintPO(TreeNode *root){
   if(root){
			PrintPO(root->left);
			PrintPO(root->right);
			cout<<" "<<root->data;
		}
   }
};
int main(){
    BST s1;
    int arr[]={10,20,30,40,50,60};
	int size=sizeof(arr)/sizeof(arr[0]);
    s1.root=s1.IsSorted(arr,0,size-1);
    s1.PrintPO(s1.root);
    cout << endl;
    if (s1.isBalanced(s1.root)){
        cout<<"Converted into an AVL tree"<<endl;
    }
}