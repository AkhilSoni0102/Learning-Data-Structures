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
void PrintTreeLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    queue<BinaryTreeNode<int>* > pendingNodes;
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
BinaryTreeNode<int>* ConstructTreeFromSortedArray(vector<int> &v, int Start, int End){
    if(Start > End)
        return NULL;
    int Mid = Start + (End-Start)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(v[Mid]);
    root->left = ConstructTreeFromSortedArray(v,Start, Mid-1);
    root->right = ConstructTreeFromSortedArray(v, Mid+1, End);
    return root;
}
pair<ListNode*, ListNode*>  BST_to_Sorted_LL(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<ListNode*, ListNode*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair<ListNode*, ListNode*> left = BST_to_Sorted_LL(root->left);
    pair<ListNode*, ListNode*> right = BST_to_Sorted_LL(root->right);    
    ListNode* LStart = left.first;
    ListNode* LEnd = left.second;
    ListNode* RStart = right.first;
    ListNode* REnd = right.second;
    ListNode* curr = new ListNode(root->Data);
    if(LEnd != NULL && RStart != NULL){
        LEnd->next = curr;
        curr->next = RStart;
        pair<ListNode*, ListNode*> p;
        p.first = LStart;
        p.second = REnd;
        return p;
    }
    else if(LEnd == NULL && RStart != NULL){
        curr->next = RStart;
        pair<ListNode*, ListNode*> p;
        p.first = curr;
        p.second = REnd;
        return p;
    }
    else if(LEnd != NULL && RStart == NULL){
        LEnd -> next = curr;
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
pair<pair<int, int>, int> Check_BST_BottomtoTop(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<pair<int, int>, int> p;
        p.first.first = 1;
        p.first.second = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<pair<int, int>, int> left = Check_BST_BottomtoTop(root->left);
    pair<pair<int, int>, int> right = Check_BST_BottomtoTop(root->right);
    int LCheck = left.first.first;
    int LMin = left.first.second;
    int LMax = left.second;
    int RCheck = right.first.first;
    int RMin = right.first.second;
    int RMax = right.second;
    if(root->Data > LMax && root->Data <= RMin && LCheck && RCheck){
        pair<pair<int, int>, int> p;
        p.first.first = 1;
        p.first.second = min(LMin, min(RMin, root->Data));
        p.second = max(LMax, max(RMax, root->Data));
        return p;
    }
    pair<pair<int, int>, int> p;
    p.first.first = 0;
    p.first.second = min(LMin, min(RMin, root->Data));
    p.second = max(LMax, max(RMax, root->Data));
    return p;
}
int Check_BST_ToptoBottom(BinaryTreeNode<int>* root, int Min = INT_MIN, int Max = INT_MAX){
    if(root == NULL)
        return 1;
    if(root->Data > Min && root->Data <= Max){
        return Check_BST_ToptoBottom(root->left, Min, root->Data-1) && Check_BST_ToptoBottom(root->right, root->Data, Max);
    }
    return 0;
}
int Search_BST(BinaryTreeNode<int>* root, int Node){
    if(root == NULL)
        return 0;
    if(root->Data == Node)
        return 1;
    else if(root->Data > Node)
        return Search_BST(root->left, Node);
    else 
        return Search_BST(root->right, Node);
}

template<typename T>
class BST{
    public:
    T Data;
    BST* right;
    BST* left;
    BST(T Data){
        this -> Data = Data;
        right = NULL;
        left = NULL;
    }
    ~BST(){
        delete left
        delete right;
    }
    int Search_BST(int Node){
        if(this == NULL)
            return 0;
        if(this->Data == Node)
            return 1;
        if(this->Data > Node)
            return Search_BST(Node));
        else 
            right->Search_BST(Node);
    }
    void insert(int Node){
        if(this == NULL)
            return ;
        if(this->Data > Node){
            if(left == NULL){
                BST<int>* New = new BST<int>(Node);
                left = New;
            }
            else if(left->Data < Node){
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
            else if(right->Data > Node){
                BST<int>* New = new BST<int>(Node);
                BST<int>* temp = right;
                right = New;
                New->right = temp;
            }
            else 
                right->insert(Node);
        }
    }
    int Smallest(){
        if(this == NULL)
            return INT_MAX;
        return min(this->Data, min(left->Smallest, right->Smallest));
    }
    void Delete_Node(int Node){
        if(this == NULL)
            return;
        if(this->Data == Node){
            BST<int>* curr = this;
            if(left == NULL && right == NULL)
                this = NULL;
            else if(left == NULL && right != NULL)
                this = right;
            else if(left != NULL && right == NULL)
                this = left;
            else{
                int val = right->Smallest();
                this -> Data = val;
                right->Delete_Node(val);
            }
        }
        else if(this->Data > Node)
            left->Delete_Node(Node);
        else 
            right->Delete_Node(Node);
    }

};

int main(){
    BST<int>* root = takeInputLevelWise();

    /*BinaryTreeNode<int>* root = takeInputLevelWise();

    for(int i = 0;i < 15;i++)
        cout<<"-";
    cout<<endl;
    
    cout<<"Tree: "<<endl;
    PrintTreeLevelWise(root);
    
    for(int i = 0;i < 15;i++)
        cout<<"-";
    cout<<endl;
    
    cout<<"Linked List: "<<endl;
    pair<ListNode*, ListNode*> Head = BST_to_Sorted_LL(root);
    ListNode* temp = Head.first;
    while(temp != NULL){
        cout<<temp->Data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
    for(int i = 0;i < 15;i++)
        cout<<"-";
    cout<<endl;
    
    cout<<"Check BST Top to Bottom Approach: "<<Check_BST_ToptoBottom(root)<<endl;
    
    for(int i = 0;i < 15;i++)
        cout<<"-";
    cout<<endl;
    
    pair<pair<int, int>, int> p = Check_BST_BottomtoTop(root);
    cout<<"Check BST Bottom to Top ApproachL "<<p.first.first<<endl;
    
    for(int i = 0;i < 15;i++)
        cout<<"-";
    cout<<endl;

    cout<<"Check whether 7 is present in the tree: "<<Search_BST(root, 7)<<endl;

    for(int i = 0;i < 15;i++)
        cout<<"-";
    cout<<endl;
    
    vector<int> v;
    cout<<"Constructed BST from sorted Array: "<<endl;
    for(int i = 1;i<=10;i++)
        v.push_back(i);
    BinaryTreeNode<int>* New = ConstructTreeFromSortedArray(v, 0, 9);
    PrintTreeLevelWise(New);*/
    
}