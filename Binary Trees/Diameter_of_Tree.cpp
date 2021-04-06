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
		cout<<"Enter the left Child of: "<<front->Data<<endl;
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


pair<int,int> HeightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<int,int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = HeightDiameter(root->left);
	pair<int, int> rightAns = HeightDiameter(root->right);
	int lh = leftAns.first;
	int ld = leftAns.second;
	int rh = rightAns.first;
	int rd = rightAns.second;
	
	int Height = 1 + max(lh,rh);
	int diameter = max(lh+rh,max(ld,rd));
	
	pair<int, int> p;
	p.first = Height;
	p.second = diameter;
	return p;
}


int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	pair<int,int> p;
	p = HeightDiameter(root);
	cout<<"Height: "<<p.first<<endl;
	cout<<"Diameter: "<<p.second;
}
