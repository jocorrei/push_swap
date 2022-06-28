#include "../includes/push_swap.h"

void push(node **stack_one, node **stack_two)
{
	node *temp;
	node *head_b;

	temp = *stack_one;
	head_b = *stack_two;
	if(temp->next)
	{
		*stack_one = (*stack_one)->next;
		(*stack_one)->prev = NULL;
	}
	else
		*stack_one = NULL;
	if (!head_b)
	{
		temp->next = NULL;
		*stack_two = temp;
	}
	else
	{
		*stack_two = temp;
		(*stack_two)->next = head_b;
		(*stack_two)->next->prev = *stack_two;
	}
}

void push_a(node **stack_one, node **stack_two)
{
	if (!*stack_two)
		return ;
	push(stack_two, stack_one);
	write(1, "pa\n", 3);
	return ;
}

void push_b(node **stack_one, node **stack_two)
{
	if (!*stack_one)
		return ;
	push(stack_one, stack_two);
	write(1, "pb\n", 3);
	return ;
}