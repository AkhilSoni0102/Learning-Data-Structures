#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T Data;
    vector<TreeNode<int>*> children;

    TreeNode(T Data){
        this -> Data = Data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter rootData: "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the Number of Children of: "<<front->Data<<endl;
        cin>>numChild;
        for(int i = 0;i < numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of: "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void Print_At_Level_K(TreeNode<int>* root, int k){
    if(root == NULL)
        return;
    if(k == 0){
        cout<<root->Data<<" ";
        return;
    }
    for(int i = 0;i < root->children.size();i++){
        Print_At_Level_K(root->children[i],k-1);
    }
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    int k;
    k = 2;
    Print_At_Level_K(root,k);
}