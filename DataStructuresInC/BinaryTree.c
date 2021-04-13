#include <stdio.h>
#include <stdlib.h>
#include "structures_and_algs.h"


int main(int argc, char *argv[]) {
	printf("%s\n", "Hello from BST!");
	
	// Create the tree
	Tree_node *tree = insert_node(NULL, 10);
	insert_node(tree, 5);
	insert_node(tree, 15);
	print_node(tree);
	print_node(tree->left);
	print_node(tree->right);

	free(tree);
	return 0;
}


void print_node(Tree_node *node) {
	printf("Value: %d\n", node->value);
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
		root->left = insert_node(root->left, value);
	
	// if value > parent's value, recur right
	} else if (value > root->value) {
		root->right = insert_node(root->right, value);
	}	
	
	return root;
}

/*Tree_node remove_node(int value) {
	// Do Stuff
}*/

