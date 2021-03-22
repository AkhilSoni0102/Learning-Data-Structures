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
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the number of Child of "<<front->Data<<endl;
        cin>>numChild;
        for(int i = 0;i<numChild;i++)
        {
            int ChildData;
            cout<<"Enter "<<i<<"th child of "<<front->Data<<endl;
            cin>>ChildData;
            TreeNode<int>* child = new TreeNode<int>(ChildData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void PrintLevelWise(TreeNode<int>* root){
    if(root == NULL)
        return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->Data<<":";
        for(int i = 0;i<front->children.size();i++){
            cout<<front->children[i]->Data<<" ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int main(){
    TreeNode<int>* root  = takeInputLevelWise();
    PrintLevelWise(root);
}