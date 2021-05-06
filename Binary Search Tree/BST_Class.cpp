#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BST{
    public:
    T Data;
    BST* right;
    BST* left;
    BST(T Data){
        this->Data = Data;
        right = NULL;
        left = NULL;
    }
    BST<int>* Search(T Node){
        if(this == NULL)
            return NULL;
        if(this->Data == Node)
            return this;
        BST<int>* Left = left->Search(Node);
        BST<int>* Right = right->Search(Node);
        if(Left == NULL && Right == NULL)
            return NULL;
        else if(Left == NULL && Right != NULL)
            return Right;
        else 
            return Left;
    }
    bool hasData(T Node){
        if(this == NULL)
            return false;
        if(this->Data == Node)
            return true;
        if(this->Data > Node)
            return left->hasData(Node);
        else 
            return right->hasData(Node);
    }
    void insert(int Node){
        if(this == NULL)
            return ;
        if(this->Data > Node){
            if(left == NULL){
                BST<int>* New = new BST<int>(Node);
                left = New;
            }
            else if(left->Data > Node && this->Data < Node){
                BST<int>* New = new BST<int>(Node);
                BST<int>* temp = left;
                left = New;
                New->right = temp;
            }
            else 
                left->insert(Node);
        }
        else 
        {
            if(right == NULL){
                BST<int>* New = new BST<int>(Node);
                right = New;
            }
            else if(right->Data > Node && this->Data < Node){
                BST<int>* New = new BST<int>(Node);
                BST<int>* temp = right;
                right = New;
                New->right = temp;
            }
            else 
                right->insert(Node);
        }
    }
    
    BST<int>* Smallest(BST<int>* root){
        if(root == NULL)
            return NULL;
        
    }

    void Delete_Node(int Node){
        if(this == NULL){
            delete this;
            return;
        }
        BST<int>* root = this;
        if(root->Data == Node){
            if(root->left == NULL && root->right == NULL)
                delete this;
            else if(root->left == NULL && root->right != NULL){
                BST<int>* temp = this;
                this = temp->right;
                temp->right = NULL;
                delete temp;
            }
            else if(root->left != NULL && root->right == NULL){
                BST<int>* temp = this;
                this = temp->left;
                temp->left = NULL;
                delete temp;
            }
            else{
                BST<int>* Smallest = right;
                while(Smallest->left != NULL)
                    Smallest = Smallest->left;
                int Min = Smallest->Data;
                this->Data = Min;
                Smallest->Delete_Node(Min);
            }
        }
        else if(this->Data > Node)
            left -> Delete_Node(Node);
        else 
            right -> Delete_Node(Node);
    }
};


void printLevelWise(BST<int>* root){
    if(root == NULL)
        return ;
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BST<int>* front = pendingNodes.front();
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
BST<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter rootData: "<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BST<int>* root = new BST<int>(rootData);
    queue<BST<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BST<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"Enter the left Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BST<int>* leftChild = new BST<int>(childData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }
        cout<<"Enter the right Child of: "<<front->Data<<endl;
        cin>>childData;
        if(childData != -1){
            BST<int>* rightChild = new BST<int>(childData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

int main(){
    BST<int>* root = takeInputLevelWise();
    root->Delete_Node(8);
    printLevelWise(root);
}