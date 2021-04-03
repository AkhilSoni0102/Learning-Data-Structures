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
        right =  NULL;
        left = NULL;
    }

    ~BinaryTreeNode(){
        delete right;
        delete left;
    }
};

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter rootData: "<<endl;
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
        cout<<"Enter the left Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter the right child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}
int Maximum(BinaryTreeNode<int>* root){
    if(root == NULL)
        return INT_MIN;
    return max(root->Data, max(Maximum(root->left), Maximum(root->right)));
}

int Minimum(BinaryTreeNode<int>* root){
    if(root == NULL)
        return INT_MAX;
    return min(root->Data, min( Minimum(root->left), Minimum(root->right)));
    
}

int Check_BST(BinaryTreeNode<int>* root){
    if(root == NULL)
        return true;
    int leftMax = Maximum(root->left);
    int rightMax = Minimum(root->right);
    bool output = (root->Data > leftMax) && (root->Data <= rightMax) && Check_BST(root->left) && Check_BST(root->right);
    return output;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout<<Check_BST(root);
}