#include "../includes/push_swap.h"

static void rev_and_push(node **stack_a, node **stack_b, int i)
{
    if (i == 0)
        push_b(stack_a, stack_b);
    else if (i == 1)
    {
        swap_a(*stack_a);
        push_b(stack_a, stack_b);
    }
    else if (i == 2)
    {
        rev_rotate_a(stack_a);
        rev_rotate_a(stack_a);
        push_b(stack_a, stack_b);
    }
    else
    {
        rev_rotate_a(stack_a);
        push_b(stack_a, stack_b);
    }
    return ;
}

void push_smaller(node **stack_a, node **stack_b)
{
    int i;
    int smaller;
    node *ptr;

    ptr = *stack_a;
    i = 0;
    smaller = ptr->value;
    while (ptr->next)
    {
        ptr = ptr->next;
        if (ptr->value < smaller)
            smaller = ptr->value;
    }
    ptr = *stack_a;
    while (ptr->value != smaller)
    {
        ptr = ptr->next;
        i++;
    }
    rev_and_push(stack_a, stack_b, i);
    return ;
}