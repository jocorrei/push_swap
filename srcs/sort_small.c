#include "../includes/push_swap.h"

void sort_small(node **stack_a, node **stack_b)
{
    (void)stack_b;
    if (count_stack(*stack_a) == 2)
        swap_a(*stack_a);
    else if (count_stack(*stack_a) == 3)
    {
        swap_a(*stack_a);
        if (ft_atoi((*stack_a)->value) < ft_atoi((*stack_a)->next->value))
            rev_rotate_a(stack_a);
        else
            rotate_a(stack_a);
        if(!is_sorted(*stack_a))
            swap_a(*stack_a);
    }
    return ;
}