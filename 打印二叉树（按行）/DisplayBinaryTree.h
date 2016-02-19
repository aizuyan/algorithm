typedef struct _node {
	int value;
	struct _node *left;
	struct _node *right;
}node;

typedef struct _list {
	node * node;
	struct _list *next;
}list;

node *createBinaryTree();
node *createNode();
list *createList();
