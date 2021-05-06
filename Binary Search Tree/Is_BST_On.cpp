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
    cout<<"Enter the rootData: "<<endl;
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
        cout<<"Enter the left child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }
        cout<<"Enter the right child of: "<<front->Data<<endl;
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

pair<pair<int, int>, int> IsBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<pair<int, int>, int> p;
        p.first.first = INT_MAX;
        p.first.second = INT_MIN;
        p.second = 1;
        return p;
    }

    pair<pair<int, int>, int> lAns = IsBST(root->left);
    pair<pair<int, int>, int> rAns = IsBST(root->right);
    int lMax = lAns.first.second;
    int lMin = lAns.first.first;
    int lIsBST = lAns.second;
    int rMax = rAns.first.second;
    int rMin = rAns.first.first;
    int rIsBST = rAns.second;
    pair<pair<int, int>, int> p;
    if(rIsBST && lIsBST && lMax < root->Data && rMin >= root->Data)
        p.second = 1;
    else 
        p.second = 0;
    p.first.first = min(root->Data, min(lMin, rMin));
    p.first.second = max(root->Data, max(lMax, rMax));
    return p;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<endl;
    pair<pair<int, int>, int> p = IsBST(root);
    cout<<p.second;
}