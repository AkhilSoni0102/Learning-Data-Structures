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
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the rootData: "<<endl;
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
        cout<<"Enter the left child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }
        cout<<"Enter the right child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

BinaryTreeNode<int>* SearchBST(BinaryTreeNode<int>* root, int K){
    if(root == NULL)
        return NULL;
    if(root -> Data == K)
        return root;
    else if(root -> Data > K)
        return SearchBST(root->left, K);
    else 
        return SearchBST(root->right, K);
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    BinaryTreeNode<int>* search = SearchBST(root, 5);
    cout<<endl<<search->Data;
}