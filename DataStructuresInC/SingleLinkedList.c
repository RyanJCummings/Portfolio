/* Creates a singly linked list and associated functions
 * Note there is only one kind of list_node struct in the header
 * file so some member data is set that isn't strictly required for
 * a singly linked list. Those members are used in the other linked lists
 * in this directory. */

#include <stdio.h>
#include <stdlib.h>
#include "structures_and_algs.h"


int main(int argc, char **argv) {
	list_node *head = NULL;
	insert_first(&head, 1);
	print_list(head);
	insert_first(&head, 2);
	print_list(head);
	insert_last(&head, 3);
	print_list(head);
	remove_list_node(&head, 2);
	print_list(head);
	free_list(head);

	return 0;
}


list_node* create_list_node(int value) {
	list_node* new = malloc(sizeof(struct list_node));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;

	return new;
}

void free_list(list_node *head) {
	list_node *temp = head;

	while(temp != NULL) {
		temp = temp->next;
		free(temp);
	}
}

void insert_first(list_node **head, int value) {
	list_node *new = create_list_node(value);
	
	// Insert new node at front of list
	new->next = *head;
	*head = new;
}

void insert_last(list_node **head, int value) {
	// Temp iterates through list while allowing the head node to be returned later
	list_node *iter = *head;
	list_node *new = create_list_node(value);
	
	// Find last node in the list
	while(iter->next != NULL) {
		iter = iter->next;
	}

	// Insert new node into list
	iter->next = new;
}

/*list_node* insert_after(list_node *node, int value) {
	while(node->next != NULL && node->next
	return node;
}*/

void remove_list_node(list_node **head, int value) {
	list_node *iter = *head;

	// Loop throught the list until the target value is a member of the NEXT node
	while(iter->next != NULL && iter->next->value != value) {
		iter = iter->next;
	}

	if (iter->next == NULL) {
		printf("%s\n", "Node is not present in the list");
	}

	else {
		iter->next = iter->next->next;
		free(iter->next);
	}
}

void print_list(list_node *head) {
	printf("%s\n", "Printing Linked List");
	while(head != NULL) {
		printf("%d\n", head->value);
		head = head->next;
	}
}
