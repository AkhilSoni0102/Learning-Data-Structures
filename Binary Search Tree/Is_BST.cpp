#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T Data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T Data){
        this -> Data = Data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter rootData: "<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"Enter left Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter the right Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

int Is_BST(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    if(root->left != NULL && root->right != NULL){
        if(root->left->Data < root->Data && root->right->Data > root->Data){
            return Is_BST(root->left);
            return Is_BST(root->right);
        }
        else return 0;
    }
    if(root->left == NULL && root->right != NULL){
        if(root->Data < root->right->Data)
            return Is_BST(root->right);
        else 
            return 0;
    }
    if(root->right == NULL && root->left != NULL){
        if(root->left->Data < root->Data){
            return Is_BST(root->left);
        }
        else 
            return 0;
    }
    return 1;
}


int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout<<Is_BST(root);
}