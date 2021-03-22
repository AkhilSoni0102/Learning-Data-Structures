#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T Data;
    vector<TreeNode<T>*> children;

    TreeNode(T Data){
        this -> Data = Data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data: "<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the Number of Children of "<<front->Data<<endl;
        cin>>numChild;
        for(int i = 0;i < numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


int Max_Data_Node(TreeNode<int>* root){
    int Max = root -> Data;
    for(int i = 0;i < root->children.size();i++){
        Max = max(Max,Max_Data_Node(root->children[i]));
    }
    return Max;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout<<Max_Data_Node(root);
}