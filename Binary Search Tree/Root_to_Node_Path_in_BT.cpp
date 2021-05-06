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
        cout<<"Enter the left child of: "<<front->Data<<endl;
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
            cout<<"L"<<front->left->Data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R"<<front->right->Data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

vector<int>* Root_to_Node_Path(BinaryTreeNode<int>* root, int Node){
    if(root == NULL){
        vector<int>* v = {NULL};
        return v;
    }
    if(root->Data == Node){
        vector<int>* v = new vector<int>();
        v->push_back(root->Data);
        return v;
    }
    vector<int>* left = Root_to_Node_Path(root->left, Node);
    vector<int>* right = Root_to_Node_Path(root->right, Node);
    if(left != NULL){
        left->push_back(root->Data);
        return left;
    }
    if(right != NULL){
        right->push_back(root->Data);
        return right;
    }
    return NULL;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    vector<int>* v = Root_to_Node_Path(root, 7);
    for(int i = 0;i < v->size();i++)
        cout<<v->at(i)<<" ";
    delete v;
}





/*#include<bits/stdc++.h>
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

vector<int>* Root_to_Node_Path(BinaryTreeNode<int>* root, int Node){
    if(root == NULL){
        vector<int>* v = {NULL};
        return v;
    }
    if(root->Data == Node){
        vector<int>* v = new vector<int>();
        v->push_back(root->Data);
        return v;
    }
    vector<int>* Left = Root_to_Node_Path(root->left, Node);
    vector<int>* Right = Root_to_Node_Path(root->right, Node);
    if(Left != NULL){
        Left->push_back(root->Data);
        return Left;
    }
    if(Right != NULL){
        Right->push_back(root->Data);
        return Right;
    }
    else return NULL;
}
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    vector<int>* output = Root_to_Node_Path(root, 7);
    for(int  i = 0;i < output->size();i++)
        cout<<output->at(i)<<" ";
    
}*/