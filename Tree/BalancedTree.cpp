#include<iostream>

using namespace std;

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
