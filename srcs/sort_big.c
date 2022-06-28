#include "../includes/push_swap.h"

void sort_big(node **stack_a, node **stack_b)
{
    (void)stack_a;
    (void)stack_b;
    int i;
    int value;
    node *ptr;
    node *test;
    
    i = 0;
    ptr = *stack_a;
    i = count_stack(*stack_a)/2;
    while (--i)
        ptr = ptr->next;
    value = ptr->value;

    ptr = *stack_a;
    while (ptr->value < value && ptr->next)
    {
        ptr = ptr->next;
        (*stack_a)->chunk = 1;
        push_b(stack_a, stack_b);
    }

    printf("\nprinting stack_copy");
    test = list_copy(*stack_a);
    print_stack(test);

    printf("\ntesting middle sort algo: %d, %d, %d, %d", i, value, ptr->value, (*stack_a)->chunk);
    return;
}