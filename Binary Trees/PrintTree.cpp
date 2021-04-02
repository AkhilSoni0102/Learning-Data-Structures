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

void PrintTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    cout<<root->Data<<": ";
    if(root->left != NULL)
        cout<<"L"<<root->left->Data<<" ";
    if(root->right != NULL)
        cout<<"R"<<root-> right->Data<<" ";
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    PrintTree(root);
    delete root;
}