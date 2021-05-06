#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T Data;
    BinaryTreeNode* right;
    BinaryTreeNode* left;

    BinaryTreeNode(T Data){
        this -> Data = Data;
        right = NULL;
        left = NULL;
    }

    ~BinaryTreeNode(){
        delete right;
        delete left;
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
        cout<<"Enter the left Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }
        cout<<"Enter the right Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

int Max(BinaryTreeNode<int>* root){
    if(root == NULL)
        return INT_MIN;
    return max(root->Data, max(Max(root->left), Max(root->right)));
}

int Min(BinaryTreeNode<int>* root){
    if(root == NULL)
        return INT_MAX;
    return min(root->Data, min(Min(root->left), Min(root->right)));
}

int IsBST(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 1;
    if(root->Data > Max(root->left) && root->Data <= Min(root->right))
        return IsBST(root->left) && IsBST(root->right);
    else 
        return 0;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout<<IsBST(root);
}

