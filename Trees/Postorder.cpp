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
    cout<<"Enter root Data:"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the Number of Children of "<<front->Data<<endl;
        cin>>numChild;
        for(int i = 0;i < numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th Child of "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int>* Child = new TreeNode<int>(childData);
            front->children.push_back(Child);
            pendingNodes.push(Child);
        }
    }
    return root;
}

void postorder(TreeNode<int> * root){
    for(int i = 0;i < root->children.size(); i++){
        postorder(root->children[i]); 
    }
    cout<<root->Data<<" ";
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    postorder(root);
}