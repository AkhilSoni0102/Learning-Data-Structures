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
    while(pendingNodes.size()!= 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"enter the left Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1)
        {
            BinaryTreeNode<int>* leftchild = new BinaryTreeNode<int>(childData);
            front->left = leftchild;
            pendingNodes.push(leftchild);
        }
        cout<<"enter the right Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1)
        {
            BinaryTreeNode<int>* rightchild = new BinaryTreeNode<int>(childData);
            front->right = rightchild;
            pendingNodes.push(rightchild);
        }
    }
    return root;
}


void InorderPrint(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    InorderPrint(root->left);
    cout<<root->Data<<" ";
    InorderPrint(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    InorderPrint(root);
}