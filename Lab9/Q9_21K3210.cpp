//Qasim Hasan
//21K-3210
//BCS-3J
//LAB 9
//QUESTION 9
//Balance factor of each node in a AVL Tree
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int key;
    TreeNode *left;
    TreeNode *right;
    int height;
};
int height(TreeNode *N){
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
TreeNode* newNode(int key){
    TreeNode* node = new TreeNode();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
TreeNode *rightRotate(TreeNode *y){
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}
TreeNode *leftRotate(TreeNode *x){
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
int getBalance(TreeNode *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
TreeNode* insert(TreeNode* node, int key){
    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(TreeNode *root){
    if(root != NULL){
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(){
    TreeNode *root = NULL;
    root = insert(root, 30);
    root=insert(root, 15);
    root = insert(root, 45);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 43);
    root = insert(root, 50);
    //                     30(0)
    //                   _____|_____
    //                  |           |
    //               15(0)        45(0)
    //                __|__        __|__
    //               |     |       |    |
    //             10(0)  20(0)   43(0)  50(0)
    //
    cout<< " " << getBalance(root);               //0
    cout<< " " << getBalance(root->left);         //0
    cout<< " " << getBalance(root->right);        //0
    cout<< " " << getBalance(root->left->left);   //0
    cout<< " " << getBalance(root->left->right);  //0
    cout<< " " << getBalance(root->right->left);  //0
    cout<< " " << getBalance(root->right->right); //0
    cout<< endl;
    cout << "Preorder traversal of the AVL tree is \n";
    preOrder(root);
}