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
        int leftChildData;
        cout<<"Enter left Child of: "<<front->Data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        cout<<"Enter the right Child of: "<<front->Data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void PrintLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->Data<<": ";
        if(front->left != NULL)
        {
            cout<<front->left->Data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<front->right->Data<<" ";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    PrintLevelWise(root);
}