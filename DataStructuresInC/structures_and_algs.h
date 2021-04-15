#ifndef STRUCTURES_AND_ALGS
#define STRUCTURES_AND_ALGS

/* structs and function prototypes for BST */
typedef struct tree_node {
	int value;
	struct tree_node *left;
	struct tree_node *right;
} tree_node;

void free_tree_memory(tree_node *);
void print_node(tree_node *);
tree_node* create_node(int);
tree_node* insert_node(tree_node *, int);
int print_inorder(tree_node *);
int print_preorder(tree_node *);
int print_postorder(tree_node *);
tree_node* find_inorder_successor(tree_node *); 
tree_node* remove_node(tree_node *,int);
#endif
