// Binary Search Tree - Data Structure - Learning 
// Copyright OM Bharatiya

#include<iostream>
#include<queue>
#include <limits>


using namespace std;

int INT_MIN = std::numeric_limits<int>::min(); // minimum value
int INT_MAX = std::numeric_limits<int>::max();

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

BstNode* SearchNode(BstNode* root, int data) {
	if(root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (data <= root->data) return SearchNode(root->left, data);
	else return SearchNode(root->right, data);
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


BstNode* FindMinNode(BstNode* root) {
	if(root==NULL) {
		cout<<"NULL ROOT ERROR";
		return NULL;
	}
	else if (root->left == NULL) {
		return root;
	}
	else
		return FindMinNode(root->left);
}
BstNode* FindMaxNode(BstNode* root) {
	if(root==NULL) {
		cout<<"NULL ROOT ERROR";
		return NULL;
	}
	else if (root->right == NULL) {
		return root;
	}
	else
		return FindMaxNode(root->right);
}

int FindHeight(BstNode* root) {
	if(root == NULL) {
		return -1;
	}
	else
		return (max(FindHeight(root->left), FindHeight(root->right)) + 1);
}
void TopView(BstNode* root) {
	if(root == NULL) return;
	if(FindHeight(root->left)>=FindHeight(root->right)) {
		while(root->left!=NULL) {
			cout<<root->data<<" ";
			root=root->left;
		}
	}else {
		while(root->right!=NULL) {
			cout<<root->data<<" ";
			root=root->right;
		}
	}
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

void PreOrderTraversal(BstNode* root) {
	if(root == NULL) return;
	cout << root -> data << "  ";
	if(root->left != NULL) PreOrderTraversal(root->left);
	if(root->right != NULL) PreOrderTraversal(root->right);
}

void PostOrderTraversal(BstNode* root) {
	if(root == NULL) return;
	if(root->left != NULL) PostOrderTraversal(root->left);
	if(root->right != NULL) PostOrderTraversal(root->right);
	cout << root -> data << "  ";
}

void InOrderTraversal(BstNode* root) {
	if(root == NULL) return;
	if(root->left != NULL) InOrderTraversal(root->left);
	cout << root -> data << "  ";
	if(root->right != NULL) InOrderTraversal(root->right);
}

bool IsSubtreeLesser(BstNode* root, int value) {
	if(root == NULL ) return true;
	if((root->data <= value) && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value)) return true;
	else return false;
}

bool IsSubtreeGreater(BstNode* root, int value) {
	if(root == NULL ) return true;
	if((root->data > value) && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value)) return true;
	else return false;
}

bool IsBST(BstNode* root) {
	if(root==NULL) return true;
	if( IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right))
		return true;
	else return false;
}

bool IsBSTUtil(BstNode* root, int min, int max) {
	if(root == NULL) return true;
	// cout << "\n*****" << min << "\t" << root->data << "\t" << max;
	if( (root->data > min) && (root->data <= max) && IsBSTUtil(root->left, min, root->data) && IsBSTUtil(root->right, root->data, max))
		return true;
	else
		return false;
}

bool IsBST_New(BstNode* root) {
	return IsBSTUtil(root, INT_MIN, INT_MAX);
}

BstNode* rightMin(BstNode* node) {
	if(node == NULL ) return NULL;
	if(node->left == NULL) 
		return node;
	else
		return rightMin(node->left);
}

BstNode* leftMax(BstNode* node) {
	if(node == NULL ) return NULL;
	if(node->right == NULL) 
		return node;
	else
		return leftMax(node->right);
}

// void deleteNode(BstNode* root, int value) {
	// if(root == NULL) 
		// cout << "NO NODE PRESENT";
	// if(root->data == value)
		
	
// }




BstNode* Delete(BstNode* root, int value) {
	if(root==NULL) return root;
	else if (value< root->data) root->left = Delete(root->left, value);
	else if (value> root->data) root->right = Delete(root->right, value);
	else {
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root=NULL;
		}
		
		else if(root->left == NULL) {
			BstNode* temp = root;
			root = root->right;
			delete temp;
		}
		
		else if(root->right == NULL) {
			BstNode* temp = root;
			root = root->left;
			delete temp;
		}
		
		else {
			BstNode* temp = FindMinNode(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
		// else {
			// BstNode* temp = FindMaxNode(root->left);
			// root->data = temp->data;
			// root->left = Delete(root->left, temp->data);
		// }
	}
	return root;
}


// char * myPath;
// char * pathPrint(BstNode *r, int n) {
	
	// if(pathExist(r,n)) {
		
		// if(r==NULL) {
			// myPath+=n;
		// }
		// else if(r->left==NULL && r->right==NULL) {
			// myPath+=r->data;
		// }
		// else {
				// if(pathExist(r->left, n-r->data))
					// myPath+=r->data;
				// else if (pathExist(r->right, n-r->data))
					// myPath+=r->data;
				// else
					// myPath=myPath;
		// }
		
		// return myPath;
	// }	
	// else
		// cout<<"\nNo path Exist";
// }

// Check if the path exists

bool pathExist(BstNode *r, int n) {
	if(r==NULL) {
		return (n==0);
	}
	else if(r->left==NULL && r->right==NULL) {
		return (n-r->data==0);
	}
	else
		return (pathExist(r->left, n-r->data) || pathExist(r->right, n-r->data));
	
}
void pathPrint(BstNode *r, int n) {
	
	if(pathExist(r,n)) {
		
		cout<<" "<<r->data;
		if(n-r->data!=0) {
			pathPrint(r->left, n-r->data);
			pathPrint(r->right, n-r->data);
		}
		
	}
	else return;
	
}

bool isPath(BstNode *r, int n, int track[], int t, int h) {
	// if(t==h) return true;
	if(r==NULL) return (n==0);
	if(pathExist(r->left,n-r->data)) {
		track[t]=r->data;
		if(isPath(r->left,n-r->data,track,t+1,h)) return true;
		else
			track[t]=0;
	}
	if(pathExist(r->right,n-r->data)) {
		track[t]=r->data;
		if(isPath(r->right,n-r->data,track,t+1,h)) return true;
		else
			track[t]=0;
	}
	return false;
}

void pathPrintBT(BstNode *r, int n) {
	
	int h=FindHeight(r);
	if(h!=-1) {
		int track[n];
		for(int i=0;i<n;i++) {
			track[i]=0;
		}
		if(isPath(r,n,track,0,h))
			PrintArr(track);
		else
			cout<<"\nNO PATH PRESENT";
	}
	else
		cout<<"\nZERO HEIGHT TREE";
}


int main() {
	BstNode* root = NULL;int num;
	// root = Insert(root, 35); root = Insert(root, 2);
	// root = Insert(root, 30); root = Insert(root, 40);
	// root = Insert(root, 5); root = Insert(root, 60);
	// root = Insert(root, 22); root = Insert(root, 8);
	// root = Insert(root, 9); root = Insert(root, 10);
	// root = Insert(root, 92); root = Insert(root, 65);
	
	
	root = Insert(root, 5); root = Insert(root, 2);
	root = Insert(root, 8); root = Insert(root, 4);
	root = Insert(root, 3); root = Insert(root, 9);
	root = Insert(root, 6); root = Insert(root, 10);
	root = Insert(root, 1); root = Insert(root, 7);
	root = Insert(root, 2); root = Insert(root, 2);
	root = Insert(root, 2); 
	
	// cout<< Search(root, 40) << "\n";
	// cout<< Search(root, 35);
	
	// // Testing the Search() function
	// cout << "Enter the no. to Search :";
	// cin >> num;
	// // Will print true if entered no. exist in the tree otherwise print false
	// cout << (Search(root, num)? "true\n": "false\n");
	
	// // to print min and max of the tree
	// cout << "Min :" << FindMin(root) <<"\nMax :" << FindMax(root) << "\n";
	// // cout << max(2,3);
	
	// // To print height of the tree
	// cout << FindHeight(root) << "\n";
	
	// // To traverse the tree in BREADTH FIRST TRAVERSAL - LEVEL ORDER TRAVERSAL
	// cout << "\nLevel Order Traversal : ";
	// LevelOrderTraversal(root);
	
	cout << "\nPre Order Traversal : ";
	// To traverse the tree in DEPTH FIRST TRAVERSAL - PRE ORDER TRAVERSAL
	PreOrderTraversal(root);
	
	// // To traverse the tree in DEPTH FIRST TRAVERSAL - POST ORDER TRAVERSAL
	// cout << "\nPost Order Traversal : ";
	// PostOrderTraversal(root);
	
	// To traverse the tree in DEPTH FIRST TRAVERSAL - IN ORDER TRAVERSAL
	cout << "\nIn-Order Traversal : ";
	InOrderTraversal(root);
	
	// // cout << "\n" << INT_MAX << "\t" << INT_MIN;
	
	
	// cout << "\n1) Checking if it is BST or not : ";
	// cout << IsBST(root);
	
	
	// cout << "\n2) Checking if it is BST or not : ";
	// cout << IsBST_New(root);
	
	
	// cout << "\nEnter the no. to Search and print subtree :";
	// cin >> num;
	// // Will print true if entered no. exist in the tree otherwise print false
	// PreOrderTraversal(SearchNode(root, num));
	
	// cout << "\nEnter the no. to Delete :";
	// cin >> num;
	// // Will print true if entered no. exist in the tree otherwise print false
	// PreOrderTraversal(Delete(root, num));
	
	cout<<"\n---------------------------";
	
	cout<<"\nPath exists for 8: "<<pathExist(root, 8);
	cout<<"\nPath exists for 14: "<<pathExist(root, 14);
	cout<<"\nPath exists for 15: "<<pathExist(root, 15);
	
	
	cout<<"\nPath for 8: ";
	pathPrint(root,8);
	
	
	cout<<"\nPath for 14: ";
	pathPrint(root,14);
	
	
	cout<<"\nPath for 15: ";
	pathPrint(root,15);
	
	
	cout<<"\n--------------BT-------------";
	
	cout<<"\nPath exists for 8: "<<pathExistBT(root, 8);
	cout<<"\nPath exists for 14: "<<pathExistBT(root, 14);
	cout<<"\nPath exists for 15: "<<pathExistBT(root, 15);
	
	
	cout<<"\nPath for 8: ";
	pathPrint(root,8);
	
	
	cout<<"\nPath for 14: ";
	pathPrint(root,14);
	
	
	cout<<"\nPath for 15: ";
	pathPrint(root,15);
	
	// if(pathExist(root, 50)){
		// cout<<"Path exists for 50";
	// }
	// else
		// cout<<"Path do not exist for 50";
	
	
	// if(pathExist(root, 62)){
		// cout<<"\nPath exists for 44";
	// }
	// else
		// cout<<"\nPath do not exist for 44";
	
	return 0;
}

