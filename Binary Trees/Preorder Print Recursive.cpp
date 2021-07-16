#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    int Data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(int Data){
        this -> Data = Data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
        delete this;
    }
}; 
void PreOrderPrint_Recursive(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout << root -> Data << " ";
    PreOrderPrint_Recursive(root -> left);
    PreOrderPrint_Recursive(root -> right);
}
