#include "../includes/push_swap.h"

int swap(node* stack)
{
    char *temp;
    node *head;
    
	temp = NULL;
    head = stack;
    if (head->value == NULL || head->next == NULL)
        return 0;
    temp = head->value;
    stack = head->next;
    head->value = stack->value;
    stack->value = temp;
    return 1;
}

void swap_a(node* stack)
{
    if (swap(stack))
        write(1, "sa\n", 3);
    else
        return ;
}

void swap_b(node* stack)
{
    if (swap(stack))
        write(1, "sb\n", 3);
    else
        return ;
}

void swap_s(node* stack_a, node* stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
    return ;
}

int rotate(node* stack)
{
	char *temp1;
	char *temp2;
	node *head;

	temp1 = NULL;
	temp2 = NULL;
	head = stack;
	while (stack->next)
		stack = stack->next;
	temp1 = stack->value;
	stack->value = head->value;
	while (stack->prev)
	{
		stack = stack->prev;
		temp2 = stack->value;
		stack->value = temp1;
		temp1 = temp2;
	}
	return 1;
}

void rotate_a(node *stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
	return ;
}

void rotate_b(node *stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
	return ;
}

void rotate_s(node *stack_a, node* stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

int rev_rotate(node *stack)
{
	node* head;
	char *temp1;
	char *temp2;

	temp1 = NULL;
	temp2 = NULL;
	head = stack;
	while (stack->next)
		stack = stack->next;
	temp2 = stack->value;	
	while (stack->prev)
		stack = stack->prev;
	temp1 = head->value;
	stack->value = temp2;
	while(stack->next)
	{
		stack = stack->next;
		temp2 = stack->value;
		stack->value = temp1;
		temp1 = temp2;
	}
	return 1;
}

void rev_rotate_a(node *stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

void rev_rotate_b(node *stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}

void rev_rotate_s(node *stack_a, node* stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}

int push(node **stack_one, node **stack_two)
{
	node *temp;
	node *head_b;
	
	temp = *stack_one;
	head_b = *stack_two;
	if (!*stack_one)
		return 0;
	*stack_one = (*stack_one)->next;
	if (!head_b)
	{
		temp->next = NULL;
		*stack_two = temp;
	}
	else
	{
		*stack_two = temp;
		(*stack_two)->next = head_b;
	}
	return 1;
}

void push_a(node **stack_one, node **stack_two)
{
	if (push(stack_two, stack_one))
		write(1, "pa\n", 3);
	return ;
}

void push_b(node **stack_one, node **stack_two)
{
	if (push(stack_one, stack_two))
		write(1, "pb\n", 3);
	return ;	
}