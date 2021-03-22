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


int Find_Height(TreeNode<int> *root){
    if(root == NULL)
        return 0;
    int Height = 1;
    for(int i = 0;i < root->children.size();i++){
        Height += max(Height, Find_Height(root->children[i]));
    }
    return Height;
}

int main(){
    TreeNode<int> *root = takeInputLevelWise();
    cout<<Find_Height(root);
}