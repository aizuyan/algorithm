#include <stdio.h>
#include <malloc.h>
#include "DisplayBinaryTree.h"

int main()
{
	node *tree;
	list *queueNow, *queueNext, *item, *queuePointer;
	tree = createBinaryTree();
	queueNow = createList();
	item = createList();
	item->node = tree;
	queueNow->next = item;
	queueNext = queueNow;
	while(queueNext->next != NULL)
	{
		queueNow = queueNext;
		queueNext = createList();
		queuePointer = queueNext;
		while(queueNow->next != NULL)
		{
			queueNow = queueNow->next;
			printf("%d ", queueNow->node->value);
			if(queueNow->node->left != NULL)
			{
				item = createList();
				item->node = queueNow->node->left;
				queuePointer->next = item;
				queuePointer = queuePointer->next;
			}
			if(queueNow->node->right != NULL)
			{
				item = createList();
				item->node = queueNow->node->right;
				queuePointer->next = item;
				queuePointer = queuePointer->next;
			}
		}
		printf("\n");
	}
	return 0;
}

node *createBinaryTree()
{
	node *head = createNode();
	head->value = 1;
	
	node *l2_1 = createNode();
	l2_1->value = 2;
	node *l2_2 = createNode();
	l2_2->value = 3;
	head->left = l2_1;
	head->right = l2_2;

	node *l3_1 = createNode();
	l3_1->value = 4;
	node *l3_2 = createNode();
	l3_2->value = 5;
	node *l3_4 = createNode();
	l3_4->value = 7;
	l2_1->left = l3_1;
	l2_1->right = l3_2;
	l2_2->right = l3_4;

	node *l4_1 = createNode();
	l4_1->value = 4;
	node *l4_2 = createNode();
	l4_2->value = 3;
	node *l4_3 = createNode();
	l4_3->value = 2;
	node *l4_7 = createNode();
	l4_7->value = 9;
	node *l4_8 = createNode();
	l4_8->value = 10;
	l3_1->left = l4_1;
	l3_1->right = l4_2;
	l3_2->left = l4_3;
	l3_4->left = l4_7;
	l3_4->right = l4_8;

	return head;
}

node *createNode()
{
	node *ret = (node *)malloc(sizeof(node));
	ret->left = NULL;
	ret->right = NULL;
	ret->value = 0;

	return ret;
}

list *createList()
{
	list *ret = (list *)malloc(sizeof(list));
	ret->node = NULL;
	ret->next = NULL;

	return ret;
}

