#include "../includes/push_swap.h"

void sort_small(node **stack_a, node **stack_b)
{
    (void)stack_b;
    
    if (count_stack(*stack_a) == 2)
        swap_a(*stack_a);
    else if (count_stack(*stack_a) == 3)
    {
        swap_a(*stack_a);
        if ((*stack_a)->value < (*stack_a)->next->value && !is_sorted(*stack_a))
            rev_rotate_a(stack_a);
        if(!is_sorted(*stack_a))
            swap_a(*stack_a);
        return ;
    }
    // else if (count_stack(*stack_a) == 4)
    // {
    //     print_stack(*stack_a);
    //     print_stack(*stack_b);
    //     push_smaller(stack_a, stack_b);
    //     sort_small(stack_a, stack_b);
    //     if (is_sorted(*stack_b))
    //         swap_b(*stack_b);
    //     push_a(stack_a, stack_b);
    //     push_a(stack_a, stack_b);
    //     return ;
    // }
    // else
    // {
    //     print_stack(*stack_a);
    //     print_stack(*stack_b);
    //     push_smaller(stack_a, stack_b);
    //     sort_small(stack_a, stack_b);
    // }
    return ;
}