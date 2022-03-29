#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct node {
	int data;
	struct node *next;
} node;

node* createLinkedList(int size);

#endif