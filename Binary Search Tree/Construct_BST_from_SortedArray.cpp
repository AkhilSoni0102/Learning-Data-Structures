#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T Data;
    BinaryTreeNode* right;
    BinaryTreeNode* left;

    BinaryTreeNode(T Data){
        this -> Data = Data;
        right = NULL;
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
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }
        cout<<"Enter the right Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->Data<<": ";
        if(front->left != NULL){
            cout<<"L: "<<front->left->Data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R: "<<front->right->Data<<" ";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

BinaryTreeNode<int>* Construct_BST_from_SortedArray(vector<int> &a, int Start, int End){
     if(Start > End)
        return NULL;
    int Mid = Start + ( End - Start )/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[Mid]);
    root->left = Construct_BST_from_SortedArray(a,Start,Mid-1);
    root->right = Construct_BST_from_SortedArray(a,Mid+1,End);
    return root;
}

int main(){
    vector<int> a;
    for(int i = 1;i <= 10;i++)
        a.push_back(i);
    BinaryTreeNode<int>* root = Construct_BST_from_SortedArray(a, 0, 9);
    printLevelWise(root);
}