#include "../includes/push_swap.h"

int rev_rotate(node **stack)
{
	node *temp;
	node *p;

	temp = *stack;
	p = *stack;
	if (!*stack || !((*stack)->next))
		return 0;
	while (p->next)
		p = p->next;
	p->prev->next = NULL;
	p->prev = NULL;
	p->next = temp;
	*stack = p;
	return 1;
}

void rev_rotate_a(node **stack)
{
	if(!rev_rotate(stack))
		return;
	write(1, "rra\n", 4);
}

void rev_rotate_b(node **stack)
{
	if(!rev_rotate(stack))
		return;
	write(1, "rrb\n", 4);
}

void rev_rotate_s(node **stack_a, node **stack_b)
{
	if(!rev_rotate(stack_a) || rev_rotate(stack_b))
		return;
	write(1, "rrr\n", 4);
}