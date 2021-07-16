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
void PreOrderPrint_Iterative(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    stack<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* top = pendingNodes.top();
        pendingNodes.pop();
        cout << top -> Data << " ";
        if(top -> right != NULL)
            pendingNodes.push(top -> right);
        if(top -> left != NULL)
            pendingNodes.push(top -> left);
    }
    cout << endl;
}
