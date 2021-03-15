#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Where is the base case? It doesn't have a base case because of the same reason as of printTree.
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter the number of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// Where is the base case? It doesn't have a base case as the size of the child node is acting like a base case.
// But for the Null tree, we should add, This is not the base case, it is an edge case.
void printTree(TreeNode<int>* root){
    if(root == NULL)
        return;
    cout<<root->data<<": ";
    for(int i  = 0;i<root->children.size();i++){
        cout<<root->children[i]->data << ",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main()
{
    /*
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int>* root = takeInput();
    printTree(root);
    // Todo delete the tree
}