#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T Data;
    vector<TreeNode<T>*> Children;

    TreeNode(T Data){
        this->Data = Data;
    }
};


// Where is the base case? It doesn't have a base case as the size of the child node is acting like a base case.
// But for the Null tree, we should add, This is not the base case, it is an edge case.
void PrintTree(TreeNode<int> * root){
    if(root == NULL) /*This is not the base case, This is an edge case as we don't have the tree*/
        return; 
    cout<<root->Data<<":";
    for(int i = 0;i<root->Children.size();i++)
        cout<<root->Children[i]->Data<<" ";
    cout<<endl;
    for (int i = 0; i < root->Children.size(); i++)
        PrintTree(root->Children[i]);
}

int main()
{
    
}