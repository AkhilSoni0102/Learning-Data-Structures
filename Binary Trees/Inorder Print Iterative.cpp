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
void Inorder_Iterative(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    stack<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.top();
        pendingNodes.pop();
        if(front -> left == NULL && front -> right == NULL){
            cout << front -> Data << " " ;
            if(pendingNodes.size() != 0){
                cout << pendingNodes.top() -> Data << " " ;
                pendingNodes.pop();
            }
            continue;
        }
        if(front -> right != NULL)
            pendingNodes.push(front -> right);
        pendingNodes.push(front);
        if(front -> left != NULL)
            pendingNodes.push(front -> left);
    } 
    
}