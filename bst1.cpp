// Binary Search Tree - Data Structure - Learning 
// Copyright OM Bharatiya

#include<iostream>
#include<queue>

using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data=data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data) {
	if(root==NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data) {
	if(root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

int FindMin(BstNode* root) {
	if(root==NULL) {
		cout<<"NULL ROOT ERROR";
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	else
		return FindMin(root->left);
}

int FindMax(BstNode* root) {
	if(root==NULL) {
		cout<<"NULL ROOT ERROR";
		return -1;
	}
	else if (root->right == NULL) {
		return root->data;
	}
	else
		return FindMax(root->right);
}

int FindHeight(BstNode* root) {
	if(root == NULL) {
		return -1;
	}
	else
		return (max(FindHeight(root->left), FindHeight(root->right)) + 1);
}

void LevelOrderTraversal(BstNode* root) {
	if(root==NULL) return;
	queue<BstNode*> q;
	q.push(root);
	
	while(!q.empty()){
		BstNode* current = q.front();
		cout << current -> data << " ";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
		q.pop();
	}
}

int main() {
	BstNode* root = NULL;int num;
	root = Insert(root, 10); root = Insert(root, 2);
	root = Insert(root, 30); root = Insert(root, 40);
	root = Insert(root, 5); root = Insert(root, 60);
	root = Insert(root, 70); root = Insert(root, 8);
	root = Insert(root, 9); root = Insert(root, 100);
	// cout<< Search(root, 40) << "\n";
	// cout<< Search(root, 35);
	
	// Testing the Search() function
	cout << "Enter the no. to Search :";
	cin >> num;
	// Will print true if entered no. exist in the tree otherwise print false
	cout << (Search(root, num)? "true\n": "false\n");
	
	// to print min and max of the tree
	cout << "Min :" << FindMin(root) <<"\nMax :" << FindMax(root) << "\n";
	// cout << max(2,3);
	
	// To print height of the tree
	cout << FindHeight(root) << "\n";
	
	// To traverse the tree in BREADTH FIRST TRAVERSAL - LEVEL ORDER TRAVERSAL
	LevelOrderTraversal(root);
	
	return 0;
}

