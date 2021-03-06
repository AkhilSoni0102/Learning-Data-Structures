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


//1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 

void PrintTreeRecursive(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout<<root->Data<<": ";
    if(root->left != NULL)
        cout<<"L"<<root->left->Data<<" ";
    if(root->right != NULL)
        cout<<"R"<<root->right ->Data<<" ";
    cout<<endl;
    PrintTreeRecursive(root->left);
    PrintTreeRecursive(root->right);
}

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
        cout<<"Enter Left child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1)
        {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter Right child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1)
        {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    PrintTreeRecursive(root);
}