#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
    public:
    int Data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int Data){
        this -> Data = Data;
        right = NULL;
        left = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

vector <int> zigZagTraversal(BinaryTreeNode* root)
{
	stack<BinaryTreeNode*> s1;
    stack<BinaryTreeNode*> s2;
    s1.push(root);
    vector<int> v;
    while(s1.size() || s2.size()){
        while(s1.size()){
            BinaryTreeNode* front = s1.top();
            s1.pop();
            v.push_back(front -> Data);
            if(front -> left != NULL)
                s2.push(front -> left);
            if(front -> right != NULL)
                s2.push(front -> right);
        }
        while(s2.size() != 0){
            BinaryTreeNode* front = s2.top();
            s2.pop();
            v.push_back(front -> Data);
            if(front -> right != NULL)
                s1.push(front -> right);
            if(front -> left != NULL)
                s1.push(front -> left);
        }
    }
    return v;
}

BinaryTreeNode* takeInputLevelWise(){
    int rootData;
    cout<<"Enter rootData: "<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"Enter Left child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1)
        {
            BinaryTreeNode* leftChild = new BinaryTreeNode(childData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"Enter Right child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1)
        {
            BinaryTreeNode* rightChild = new BinaryTreeNode(childData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode* root = takeInputLevelWise();
    zigZagTraversal(root);
}