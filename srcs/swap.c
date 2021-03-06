#include "../includes/push_swap.h"

int swap(node* stack)
{
    int temp;
    node *head;
    
    head = stack;
    if (head == NULL || head->next == NULL)
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