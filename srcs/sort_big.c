#include "../includes/push_swap.h"

static int check_last_value(node *stack, int median)
{
    node *temp;

    temp = stack;
    while (temp->next)
        temp = temp->next;
    if (temp->value < median)
        return 1;
    else
        return 0;
}


static void arrange_big_to_a(node **stack_a, node **stack_b, int chunk_size)
{
    int median;
    int i;
    median = search_median(*stack_b, (*stack_b)->chunk);
    i = 0;
    while (chunk_size)
    {
        if((*stack_b)->value > median)
        {
            push_a(stack_a, stack_b);
            chunk_size--;
        }
        else
        {
            while ((*stack_b)->value <= median && chunk_size)
            {
                rotate_b(stack_b);
                chunk_size--;
                i++;
            }  
        }
    }
    if ((*stack_a)->chunk != 1)
    {
        while (i--)
            rev_rotate_b(stack_b);
    }
    if (count_stack(*stack_b) == 2)
    {
        if (!is_chunk_sorted(*stack_b))
            swap_b(*stack_b);
        push_a(stack_a, stack_b);
        push_a(stack_a, stack_b);
        return ;
    }
    chunk_size = count_first_chunk(*stack_b);
    arrange_big_to_a(stack_a, stack_b, chunk_size);
    return ;
}

static void arrange_to_b(node **stack_a, node **stack_b, int chunk)
{
    int median;
    node *temp;
    int size;
    
    while (count_stack(*stack_a) > 2)
    {
        size = count_stack(*stack_a)/2;
        median = search_median(*stack_a, 0);
        temp = *stack_a;
        while (size)
        {
            while (temp->value < median)
            {
                temp = temp->next;
                (*stack_a)->chunk = chunk;
                push_b(stack_a, stack_b);
                size--;
            }
            if (check_last_value(*stack_a, median) && size)
            {
                rev_rotate_a(stack_a);
                (*stack_a)->chunk = chunk;
                push_b(stack_a, stack_b);
                size--;
            }
            while (temp->value >= median && size)
            {
                rotate_a(stack_a);
                temp = *stack_a;
            }
        }
        chunk++;
    }
}

static void arrange_to_a(node **stack_a, node **stack_b)
{
    int chunk_size;

    chunk_size = count_first_chunk(*stack_b);
    if (chunk_size == 1)
        push_a(stack_a, stack_b);
    else if (chunk_size == 2)
    {
        if (!is_chunk_sorted(*stack_b))
            swap_b(*stack_b);
        push_a(stack_a, stack_b);
        push_a(stack_a, stack_b);
    }
    else if (chunk_size == 3)
    {
        if (!is_chunk_sorted(*stack_b))
        {
            if ((*stack_b)->value > search_median(*stack_b, ((*stack_b)->chunk)))
                push_a(stack_a, stack_b);
            else
                swap_b(*stack_b);
            arrange_to_a(stack_a, stack_b);
        }
        else
        {
            push_a(stack_a, stack_b);
            push_a(stack_a, stack_b);
            push_a(stack_a, stack_b);
        }
    }
    else
    {
        chunk_size = count_first_chunk(*stack_b);
        arrange_big_to_a(stack_a, stack_b, chunk_size);
    }
    return;
}

void sort_big(node **stack_a, node **stack_b)
{
    arrange_to_b(stack_a, stack_b, 1);
    if (!is_sorted(*stack_a))
        rotate_a(stack_a);
    while (count_stack(*stack_b) >= 1)
        arrange_to_a(stack_a, stack_b);
    return;
}