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
        delete left;
        delete right;
    }
};
class ListNode{
    public:
    int Data;
    ListNode* next;

    ListNode(int Data){
        this -> Data = Data;
        next = NULL;
    }

    ~ListNode(){
        delete next;
    }
};

BinaryTreeNode<int>* LL_to_BST(ListNode* Head, int N){
    if(N == 0)
        return NULL;
    ListNode* temp = Head;
    for(int i = 0;i < N/2;i++){
        temp = temp -> next;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(temp -> Data);
    root -> left = LL_to_BST(Head, N/2);
    root -> right = LL_to_BST(temp -> next, (N+1)/2 - 1);
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> Data << ": ";
        if(front -> left != NULL){
            cout << "L" << front -> left -> Data << " " ;
            pendingNodes.push(front -> left);
        }
        if(front -> right != NULL){
            cout << "R" << front -> right -> Data;
            pendingNodes.push(front -> right);
        }
        cout << endl;
    }
}

int main(){
    int N;
    cin>> N;
    int x;
    cin>>x;
    ListNode* Head;
    Head = new ListNode(x);
    ListNode* temp = Head;
    ListNode* New;
    for(int i = 0;i < N-1;i++){
        cin>>x;
        New = new ListNode(x);
        temp -> next = New;
        temp = temp -> next;
    }
    ListNode* Tail = New;
    BinaryTreeNode<int>* root = LL_to_BST(Head, N);
    printTreeLevelWise(root);
}