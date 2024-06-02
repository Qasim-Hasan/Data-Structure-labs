//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 8 
//TASK 1
#include<iostream>
using namespace std;
class TreeNode{
public:
	int data;
	TreeNode* leftchild;
	TreeNode* rightchild;
    TreeNode(){}
	TreeNode(int data){
    	this->data=data;
    	rightchild=leftchild=NULL;
	}
};

class BinaryTree{
    public:
    TreeNode *root;
    BinaryTree(){
        root=NULL;
    }
void Inorder(TreeNode *root){
    if(!root)
    return;
    Inorder(root->leftchild);
    cout << root->data << " ";
    Inorder(root->rightchild);
}
void Insert(TreeNode *new_node){
    if(root==NULL){
        root=new_node;
    }else{
        TreeNode *temp=root;
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

    bool isBinaryTree(TreeNode *root){
        TreeNode *prev = NULL;
    if(root!=NULL){
        if(!isBinaryTree(root->leftchild)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBinaryTree(root->rightchild);
    }
    else{
        return 1;
    }
    }
	void AutoGraderBST(TreeNode* root){
        if(isBinaryTree(root)==0){
	    cout << "\n Zero Points Graded\n";
		}else{
    	cout << "\n Ten Points Graded\n";
	    }
    }
};
int main(){
	BinaryTree G1;
    TreeNode *root = new TreeNode(98);
    G1.Insert(root);
    TreeNode *n1 = new TreeNode(56);
    G1.Insert(n1);
    TreeNode *n2 = new TreeNode(76);
    G1.Insert(n2);
	TreeNode *n3 = new TreeNode(29);
    G1.Insert(n3); 
    TreeNode *n4 = new TreeNode(15);
    G1.Insert(n4);
    G1.Inorder(root);
	G1.AutoGraderBST(root);
}
