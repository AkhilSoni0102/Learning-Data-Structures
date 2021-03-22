#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T Data;
    vector<TreeNode<T>*> children;

    TreeNode(T Data){
        this->Data = Data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Number of Childrens of "<<front->Data<<endl;
        int numChild;
        cin>>numChild;
        for(int i =0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th Child of "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void PrintTree(TreeNode<int> * root){
    if(root == NULL) /*This is not the base case, This is an edge case as we don't have the tree*/
        return; 
    cout<<root->Data<<":";
    for(int i = 0;i<root->children.size();i++)
        cout<<root->children[i]->Data<<" ";
    cout<<endl;
    for (int i = 0; i < root->children.size(); i++)
        PrintTree(root->children[i]);
}

int main()
{
    TreeNode<int>*root = takeInputLevelWise();
    PrintTree(root);
}

