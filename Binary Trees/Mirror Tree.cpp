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
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter rootData: " << endl;
    cin >> rootData;
    if(rootData == -1)  
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << front -> Data << ": ";
        int ChildData;
        cin >> ChildData;
        if(ChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(ChildData);
            front -> left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << endl;
        cout << "Enter the right Child of " << front -> Data << ": ";
        cin >> ChildData;
        if(ChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(ChildData);
            front -> right = rightChild;
            pendingNodes.push(rightChild);
        }
        cout << endl;
    }
    return root;
}
void PrintLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> Data << ": ";
        if(front -> left != NULL){
            cout << "L" << front -> left -> Data << " ";
            pendingNodes.push(front -> left);
        }
        if(front -> right != NULL){
            cout << "R" << front -> right -> Data << " ";
            pendingNodes.push(front -> right);
        }
        cout << endl;
    }
}

void MirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    BinaryTreeNode<int>* Temp;
    Temp = root -> left;
    root -> left = root -> right;
    root -> right = Temp;
    MirrorBinaryTree(root -> left); 
    MirrorBinaryTree(root -> right);
}