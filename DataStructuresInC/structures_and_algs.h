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


/* structs and function prototypes for Linked Lists */
typedef struct list_node {
	int value;
	struct list_node *next;
	struct list_node *prev;
} list_node;

list_node* create_list_node(int value);
void free_list(list_node **);
void insert_first(list_node **, int);
void insert_last(list_node **, int);
void insert_after(list_node **, int);
void remove_list_node(list_node **, int);
void print_list(list_node *);

#endif
