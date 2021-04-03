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
        cout<<"Enter left Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            front->left = leftChild;
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

int Height_of_Tree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 +  max(Height_of_Tree(root->left),Height_of_Tree(root->right));
}

int Diameter_of_BinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    int option1 = Height_of_Tree(root->left) + Height_of_Tree(root->right);
    int option2 = Diameter_of_BinaryTree(root->left);
    int option3 = Diameter_of_BinaryTree(root->right);
    return max(option1,max(option2,option3));
}