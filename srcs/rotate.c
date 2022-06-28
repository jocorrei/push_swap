#include "../includes/push_swap.h"

int rotate(node** stack)
{
	node *temp;
	node *p;

	temp = *stack;
	if(!*stack || !(*stack)->next)
		return 0;
	p = NULL;
	*stack = (*stack)->next;
	p = *stack;
	while (p->next)
		p = p->next;
	temp->next = NULL;
	p->next = temp;
	p->next->prev = p;
	return 1;
}

void rotate_a(node **stack)
{
	if(!rotate(stack))
		return;
	write(1, "ra\n", 3);
	return ;
}

void rotate_b(node **stack)
{
	if(!rotate(stack))
		return ;
	write(1, "rb\n", 3);
	return ;
}

void rotate_s(node **stack_a, node **stack_b)
{
	if(!rotate(stack_a) || !rotate(stack_b))
		return ;
	write(1, "rr\n", 3);
}