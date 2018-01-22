// A simple C program to introduce
// a linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node 
{
  int data;
  struct Node *next;
};
 
// This function prints contents of linked list starting from 
// the given node
void printList(Node *n)
{
  while (n != NULL)
  {
     printf(" %d ", n->data);
     n = n->next;
  }
} 
Node* CreateNewNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	
	return newNode;
}

Node* InsertEnd(Node* n, int value) {
	if(n==NULL) {
		Node* start = createNewNode(value);
	}
	
	
	
	
}

void DeleteVoluntarily(Node* n) {
	Node* temp = n, *temp2;
	temp2=n->next;
	temp->data = temp2->data;
	temp->next = temp2->next;
	free(temp2);
}

void swapTwo(Node* on, Node* tw) {
	Node temp*;
	temp = on->data;
	on->data=tw->data;
	tw->data=temp;
}

int main()
{
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;
   
  // allocate 3 nodes in the heap  
  head = (Node*)malloc(sizeof(Node)); 
  second = (Node*)malloc(sizeof(Node));
  third = (Node*)malloc(sizeof(Node));
 

  head->data = 1; //assign data in first node
  head->next = second; // Link first node with the second node
   

  second->data = 2; //assign data to second node
  second->next = third; // Link second node with the third node
   
   
   
  third->data = 3; //assign data to third node
  third->next = NULL;
   
	printList(head);
	
	// DeleteVoluntarily(second);
	swapTwo(second, third);
	printList(head);
  return 0;
}