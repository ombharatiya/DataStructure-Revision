// Binary Search Tree - Data Structure - Learning 
// Copyright OM Bharatiya

#include<iostream>

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

int main() {
	BstNode* root = NULL;int num;
	root = Insert(root, 10); root = Insert(root, 20);
	root = Insert(root, 30); root = Insert(root, 40);
	root = Insert(root, 50); root = Insert(root, 60);
	root = Insert(root, 70); root = Insert(root, 80);
	root = Insert(root, 90); root = Insert(root, 100);
	// cout<< Search(root, 40) << "\n";
	// cout<< Search(root, 35);
	cout << "Enter the no. to Search :";
	cin >> num;
	cout << (Search(root, num)? "true\n": "false\n");
	cout << "Min :" << FindMin(root) <<"\nMax :" << FindMax(root);
	return 0;
}

