#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
		
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        if(root == NULL) {
            return -1;
        }
        else
            return (max(height(root->left), height(root->right)) + 1);
    }
	void leftView(Node* root) {
		if(root!=NULL) {
			leftView(root->left);
			cout<<root->data<<" ";
		}
	}
	
	void rightView(Node* root) {
		if(root!=NULL) {
			cout<<root->data<<" ";
			rightView(root->right);
		}
	}
	
	void topViewGenuine(Node* root) {
		if(root==NULL) return;
		if(root->left!=NULL) {
			leftView(root->left);
		}
		cout<<root->data<<" ";
		if(root->right!=NULL) {
			rightView(root->right);
		}
	}
	
	// void topView(Node* root) {
		
		// if(root == NULL) return;
		// else {
			// cout<<root->data<<" ";
			// if(height(root->left)>=height(root->right)) {
				// while(root->left!=NULL) {
					// cout<<root->left->data<<" ";
					// root=root->left;
				// }
			// }else {
				// while(root->right!=NULL) {
					// cout<<root->right->data<<" ";
					// root=root->right;
				// }
			// }
		// }
	// }
	
}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.height(root);
    cout << height<<"\n";
	
	// myTree.topView(root);
	cout<<"**********************";
	myTree.topViewGenuine(root);

    return 0;
}
