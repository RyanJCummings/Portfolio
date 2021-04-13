#ifndef STRUCTURES_AND_ALGS
#define STRUCTURES_AND_ALGS

/* structs and function prototypes for BST */
typedef struct Tree_node {
	int value;
	struct Tree_node *left;
	struct Tree_node *right;
} Tree_node;

void free_tree_memory(Tree_node *);
void print_node(Tree_node *);
Tree_node* create_node(int);
Tree_node* insert_node(Tree_node *, int);
Tree_node* remove_node(Tree_node *,int);
#endif
