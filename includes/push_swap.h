#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

typedef struct node {
	struct node *prev;
	int			chunk;
	int			value;
	struct node *next;
} node;

int check_digit(int argc, char **argv);
int check_repeted(int argc, char **argv);
int check_args(int argc, char **argv);
int check_interger_limits(int argc, char **argv);
void swap_a(node* stack);
void swap_b(node* stack);
void swap_s(node* stack_a, node* stack_b);
void rotate_b(node **stack);
void rotate_a(node **stack);
void rev_rotate_a(node **stack);
void rev_rotate_b(node **stack);
void print_stack(node* head);
void push_a(node **stack_one, node **stack_two);
void push_b(node **stack_one, node **stack_two);
int is_sorted(node *stack);
void sort_small(node **stack_a, node **stack_b);
int count_stack(node *stack);
void push_smaller(node **stack_a, node **stack_b);
void free_stack(node* head);
void sort_big(node **stack_a, node **stack_b);
node* list_copy(node* head);

#endif