#include "../includes/push_swap.h"

int swap(node* stack)
{
    char *temp = NULL;
    node* head;
    
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
	char *temp1 = NULL;
	char *temp2 = NULL;
	node *head = NULL;

	head = stack;
	temp1 = head->value;
	while (stack->next)
		stack = stack->next;
	temp2 = stack->prev->value;
	stack->prev->value = temp1;
	while (stack->prev != head)
	{
		stack = stack->prev;
		temp1 = stack->prev->value;
		stack->prev->value = temp2;
		temp2 = temp1;
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