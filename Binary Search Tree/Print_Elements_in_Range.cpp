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

void Print_Elements_in_Range(BinaryTreeNode<int>* root, int Min, int Max){
    if(root == NULL)
        return ;
    if(root->Data <= Max && root->Data >= Min)
        cout<<root->Data<<" ";
    if(root->Data > Max)
        Print_Elements_in_Range(root->left, Min, Max);
    else if(root->Data < Min)
        Print_Elements_in_Range(root->right, Min, Max);
    else{
        Print_Elements_in_Range(root->left, Min, Max);
        Print_Elements_in_Range(root->right, Min, Max);
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Print_Elements_in_Range(root, 20, 40);
}