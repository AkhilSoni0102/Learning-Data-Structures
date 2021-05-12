#include<bits/stdc++.h>
using namespace std;

class binaryTreeNode {
public :
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};
void Inorder_BST(binaryTreeNode* root, vector<int> &allNodes){
    if(root == NULL)
        return ;
    if(root->left != NULL)
        Inorder_BST(root->left, allNodes);
    allNodes.push_back(root->data);
    if(root->right != NULL)
        Inorder_BST(root->right, allNodes);
}

void converttoheap(binaryTreeNode* root, vector<int> &allNodes, int &Index){
    if(root == NULL)
        return ;
    root->data = allNodes[Index];
    Index++;
    converttoheap(root->left, allNodes, Index);
    converttoheap(root->right, allNodes, Index);
}
void preOrderPrint(binaryTreeNode* root){
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
void convertBST(binaryTreeNode* root)
{
	vector<int> allNodes;
    Inorder_BST(root, allNodes);
    cout<<endl;
    int Index = 0;
    converttoheap(root, allNodes, Index);
    preOrderPrint(root);
}