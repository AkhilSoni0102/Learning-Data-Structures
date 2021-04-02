#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T Data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T Data){
        this -> Data = Data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data: "<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"Enter left child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            front -> left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter the right Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}


void PrintNodesLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->Data<<": ";
        if(front->left != NULL){
            cout<<"L"<<front->left->Data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R"<<front->right->Data<<" ";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }

}

int Height_of_tree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    int Height = 0;
    Height = max(Height_of_tree(root->left),Height_of_tree(root->right));
    return Height + 1;
}

int Count_Nodes(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    int Count = 1;
    Count += Count_Nodes(root->left);
    Count += Count_Nodes(root->right);
    return Count;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    PrintNodesLevelWise(root);
    cout<<"The Height of the Tree is: "<<Height_of_tree(root)<<endl;
    cout<<"The Total Number of Nodes that the Tree Has: "<<Count_Nodes(root)<<endl;
}

