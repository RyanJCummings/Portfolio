#include <stdio.h>
#include <stdlib.h>
#include "structures_and_algs.h"


int main(int argc, char *argv[]) {
	printf("%s\n", "Hello from BST!");
	
	Tree_node *test;
	remove_node(test, 3);

	// Create the tree
	Tree_node *tree = insert_node(NULL, 10);
	insert_node(tree, 5);
	insert_node(tree, 7);
	insert_node(tree, 20);
	insert_node(tree, 11);
	insert_node(tree, 1);
	insert_node(tree, 16);

	free_tree_memory(tree);
	return 0;
}


void print_node(Tree_node *node) {
	printf("Value: %d\n", node->value);
}

Tree_node* create_node(int value) {
	Tree_node* new = (struct Tree_node*)malloc(sizeof(struct Tree_node));
	new->value = value;
	new->left = NULL;
	new->right = NULL;

	return new;
}

// Inserts new node into tree
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

// Performs in-order traversal of tree freeing memory as it goes along
// this has the effect of deleting the entire tree while 
// protecting against memory leaks
void free_tree_memory(Tree_node * root) {
	if(root == NULL) {
		return;
	} else {
		free_tree_memory(root->left);
		free_tree_memory(root->right);
		free(root);
	}
}


/*Tree_node* remove_node(Tree_node * root, int value) {
	// Base case: root is null
	if (root == NULL) {
		return root;
	}
	
	// If value is less than root's value, recur left
	if (value < root->value) {
		root->left = remove_node(root->left, value);
	} 

	// If value is greater than root's value, recur right
	else if (value > root->value) {
		root->right = remove_node(root->right, value);
	} 

	// If value equals root's value, then this is the node to delete
	else {
		// No Children
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		// 1 Child
		if (root->left != NULL || root->
	}



}*/

