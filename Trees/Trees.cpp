/*Tree having only one root node and two child node. */
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

TreeNode<int>* TakeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int N;
    cout<<"Enter the number of childeren of: "<<rootData<<endl;
    cin>>N;
    for(int i = 0; i<N;i++){
        TreeNode<int> *child = TakeInput();
        root->Children.push_back(child);
    }
    return root;

}


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
    /*TreeNode<int> *root = new TreeNode<int>(3);
    TreeNode<int> *Node1 = new TreeNode<int>(1);
    TreeNode<int> *Node2 = new TreeNode<int>(2);
    root->Children.push_back(Node1);
    root->Children.push_back(Node2);*/
    TreeNode<int> *root = TakeInput();
    PrintTree(root);
}