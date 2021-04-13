#include <stdio.h>
#include <stdlib.h>
#include "structures_and_algs.h"


int main(int argc, char *argv[]) {
	printf("%s\n", "Hello from BST!");
	Tree_node *node = create_node(5);
	print_node(*node);
	
	free(node);
	return 0;
}


void print_node(Tree_node node) {
	printf("Value: %d\n", node.value);
	//printf("Left Child: %d\n", node.left->value);
	//printf("Right Child: %d\n", node.right->value);
}

Tree_node* create_node(int value) {
	Tree_node* new = (struct Tree_node*)malloc(sizeof(struct Tree_node));
	new->value = value;
	new->left = NULL;
	new->right = NULL;

	return new;
}

Tree_node* insert_node(Tree_node* root, int value) {
	// If root is null, create a new root.
	if (root == NULL) {
		return create_node(value);
	}
	// if value < parent's value recur left
	if (value < root->value) {
		return insert_node(root->left, value);
	// if value > parent's value, recur right
	} else if (value > root->value) {
		return insert_node(root->right, value);
	}	
	// otherwise node has same key as root and is returned unchanged
	return root;
}

/*Tree_node remove_node(int value) {
	// Do Stuff
}*/

