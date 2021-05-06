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
class ListNode{
    public:
    int Data;
    ListNode* next;

    ListNode(int Data){
        this -> Data = Data;
        next = NULL;
    }
};

pair<ListNode*, ListNode*> BST_to_Sorted_LL(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<ListNode*, ListNode*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair<ListNode*, ListNode*> Left = BST_to_Sorted_LL(root->left);
    pair<ListNode*, ListNode*> Right = BST_to_Sorted_LL(root->right);
    ListNode* curr = new ListNode(root->Data);
    ListNode* LStart = Left.first;
    ListNode* Lend = Left.second;
    ListNode* RStart = Right.first;
    ListNode* Rend = Right.second;
    if(Lend != NULL && RStart != NULL){
        Lend->next = curr;
        curr->next = RStart;
        pair<ListNode*, ListNode*> p;
        p.first = LStart;   
        p.second = Rend;
        return p;
    }
    else if(Lend == NULL && RStart != NULL){
        curr->next = RStart;
        pair<ListNode*, ListNode*> p;
        p.first = curr;
        p.second = Rend;
        return p;
    }
    else if(Lend != NULL && RStart == NULL){
        Lend->next = curr;
        pair<ListNode*, ListNode*> p;
        p.first = LStart;
        p.second = curr;
        return p;
    }
    else{
        pair<ListNode*, ListNode*> p;
        p.first = curr;
        p.second = curr;
        return p;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    pair<ListNode*, ListNode*> p = BST_to_Sorted_LL(root);
    ListNode* temp = p.first;
    while(temp != p.second){
        cout<<temp->Data<<" ";
        temp = temp->next;
    }
    cout<<p.second->Data;
}