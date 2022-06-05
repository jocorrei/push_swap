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
    if(!swap(stack_a) && !swap(stack_b))
		return ;
    write(1, "ss\n", 3);
    return ;
}

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