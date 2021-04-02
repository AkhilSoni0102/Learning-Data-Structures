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

int Search_BST(BinaryTreeNode<int>* root, int B){
    if(root == NULL)
        return 0;
    if(root->Data == B)
        return 1;
    else if(root->Data > B)
        return Search_BST(root->left, B);
    else 
        return Search_BST(root->right,B);
}

void Print_Elements_in_Range(BinaryTreeNode<int> * root, int A, int B){
    if(root == NULL)    
        return ;
    if(root->Data >=A && root->Data <= B)
        cout<<root->Data<<" ";
    if(root->Data < A)
        Print_Elements_in_Range(root->right,A,B);
    else if(root->Data > B)
        Print_Elements_in_Range(root->left,A,B);
    else{
        Print_Elements_in_Range(root->left,A,B);
        Print_Elements_in_Range(root->right,A,B);
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout<<Search_BST(root, 7);
    Print_Elements_in_Range(root,2,5);
}

