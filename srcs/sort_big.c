#include "../includes/push_swap.h"

void sort_big(node **stack_a, node **stack_b)
{
    int i;
    int value;
    node *ptr;
    (void)stack_b;

    ptr = *stack_a;
    i = count_stack(*stack_a)/2;
    while (--i)
        ptr = ptr->next;
    value = ptr->value;

    ptr = *stack_a;
    while (ptr->value < value)
    {
        ptr = ptr->next;
        push_b(stack_a, stack_b);
    }

    
    // printf("\ntesting middle sort algo: %d, %d, %d", i, value, ptr->value);
    return;
}