#include "../includes/push_swap.h"

void sort_big(node **stack_a, node **stack_b)
{
    int median;
    node *temp;
    int size;
    int chunk;

    chunk = 1;
    while (count_stack(*stack_a) > 2)
    {
        size = count_stack(*stack_a)/2;
        median = search_median(*stack_a);
        temp = *stack_a;
        while (size != -1)
        {
            if (temp->value < median)
            {
                temp = temp->next;
                (*stack_a)->chunk = chunk;
                push_b(stack_a, stack_b);
            }
            else
            {
                if ((*stack_a)->value >= median)
                    rotate_a(stack_a);   
            }
            temp = *stack_a;
            size--;
        }
        chunk++;
    }
    if (!is_sorted(*stack_a))
        rotate_a(stack_a);
    print_stack(*stack_b);
    return;
}