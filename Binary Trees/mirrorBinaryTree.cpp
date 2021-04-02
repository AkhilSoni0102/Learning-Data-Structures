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
    cout<<"Enter RootData: "<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int ChildData;
        cout<<"Enter the left Child of: "<<front->Data<<endl;
        cin>>ChildData;
        if(ChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(ChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter the right Child of: "<<front->Data;
        cin>>ChildData;
        if(ChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(ChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout<<mirrorBinaryTree(root);
}