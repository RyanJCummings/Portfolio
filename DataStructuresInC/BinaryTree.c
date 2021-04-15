#include <stdio.h>
#include <stdlib.h>
#include "structures_and_algs.h"


int main(int argc, char *argv[]) {
	printf("%s\n", "Hello from BST!");
	
	// Create the tree
	Tree_node *tree = insert_node(NULL, 10);
	insert_node(tree, 5);
	insert_node(tree, 7);
	insert_node(tree, 20);
	insert_node(tree, 11);
	insert_node(tree, 1);
	insert_node(tree, 16);

	printf("%s\n", "Inorder Traversal:");
	print_inorder(tree);
	
	remove_node(tree, 7);

	printf("%s\n", "Inorder Traversal:");
	print_inorder(tree);

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
	} 

	// if value > parent's value, recur right
	else if (value > root->value) {
		root->right = insert_node(root->right, value);
	}	
	
	return root;
}

// Performs inorder traversal of tree printing the nodes at each visit
int print_inorder(Tree_node *root) {
	if (root == NULL) {
		return -1;
	}
	else {
		print_inorder(root->left);
		print_node(root);
		print_inorder(root->right);
	}

	return 0;
}

// Performs preorder traversal of tree printing the nodes at each visit
int print_preorder(Tree_node *root) {
	if (root == NULL) {
		return -1;
	}
	else {
		print_node(root);
		print_preorder(root->left);
		print_preorder(root->right);
	}

	return 0;
}

// Performs postorder traversal of tree printing the nodes at each visit
int print_postorder(Tree_node *root) {
	if (root == NULL) {
		return -1;
	}
	else {
		print_postorder(root->left);
		print_postorder(root->right);
		print_node(root);
	}

	return 0;
}


// Performs postorder traversal of tree freeing memory as it goes along
// this has the effect of deleting the entire tree while 
// protecting against memory leaks
void free_tree_memory(Tree_node * root) {
	if(root == NULL) {
		return;
	} 

	else {
		free_tree_memory(root->left);
		free_tree_memory(root->right);
		free(root);
	}
}

Tree_node* find_inorder_successor(Tree_node* node) {
	Tree_node *this = node;
	
	while(this && this->left !=NULL) {
		this = this->left;
	}
	return this;
}

Tree_node* remove_node(Tree_node *root, int value) {
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
		// No left child
		if (root->left == NULL) {
			Tree_node *temp = root->left;
			free(root);
			return temp;
		}

		// No right child
		if (root->right == NULL) {
			Tree_node *temp = root->right;
			free(root);
			return temp;
		}

		// root has two children
		Tree_node *temp = find_inorder_successor(root->right);
		root->value = temp->value;
		root->right = remove_node(root->right, temp->value);
	}
	
	return root;
}

