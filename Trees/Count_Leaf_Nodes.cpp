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
            cout<<"Enter "<<i<<"th child of "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int Count_Leaf_Nodes(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    if(root->children.size() == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++){
        ans += Count_Leaf_Nodes(root->children[i]);
    }
    return ans;
}


int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout<<Count_Leaf_Nodes(root);
}