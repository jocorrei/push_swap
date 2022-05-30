#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

typedef struct node {
	struct node *prev;
	char		*value;
	struct node *next;
} node;

int check_digit(int argc, char **argv);
int check_repeted(int argc, char **argv);
int check_args(int argc, char **argv);
int check_interger_limits(int argc, char **argv);
void swap_a(node* stack);
void swap_b(node* stack);
void swap_s(node* stack_a, node* stack_b);


#endif