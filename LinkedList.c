#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node* next;
	int value;
} Node;

void add_front(Node** head, int value){
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->value = value;
	if(!(*head)){
		new_node->next = NULL;
		(*head) = new_node;
	}else{
		new_node->next = (*head);
		(*head) = new_node;
	}
	return;
}

void remove_link(Node** head, int value_to_remove){
	Node* temp_node = NULL;
	Node* current_node = (*head);
	if((*head)->value == value_to_remove){
		(*head) = (*head)->next;
	}else{
		while(current_node){
			if(current_node->value == value_to_remove){
				temp_node = current_node->next;
				current_node->next = NULL;
				current_node = temp_node;
			}
			current_node = current_node->next;
		}
	}
	return;
}

void remove_duplicates(Node** head){
	Node* current_node = (*head);
	Node* previous_node = NULL;

	while(current_node->next){
		previous_node = current_node;
		current_node = current_node->next;
		if(previous_node->value == current_node->value){
			previous_node->next = current_node->next;
			current_node->next = NULL;
			current_node = previous_node;
		}
	}
	return;
}

void display_list(Node* head){
	Node* current_node = head;
	printf("Linked List:\n");
	while(current_node){
		printf("[%d]-->", current_node->value);
		current_node = current_node->next;
	}
	printf("NULL\n");
}
int main(int argc, char const *argv[])
{
	Node* head = NULL;

	int i ;
	for(i = 0; i<=10; i++){
		add_front(&head, i);
	}
	add_front(&head, 10);
	add_front(&head, 10);
	display_list(head);
	remove_duplicates(&head);
	remove_link(&head, 10);
	display_list(head);
	return 0;
}