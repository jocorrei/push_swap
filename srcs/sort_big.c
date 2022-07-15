#include "../includes/push_swap.h"

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
        while (size != 0)
        {
            while (temp->value < median)
            {
                temp = temp->next;
                (*stack_a)->chunk = chunk;
                push_b(stack_a, stack_b);
                size--;
            }
            while (temp->value >= median && size != 0)
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
    }
    return;
}

void sort_big(node **stack_a, node **stack_b)
{
    int chunk_size;
    int chunk;
    int median;
    int is_sort;
    
    arrange_to_b(stack_a, stack_b, 1);
    if (!is_sorted(*stack_a))
        rotate_a(stack_a);
    arrange_to_a(stack_a, stack_b);
    arrange_to_a(stack_a, stack_b);
    chunk_size = count_first_chunk(*stack_b);
    chunk = (*stack_b)->chunk;
    median = search_median(*stack_b, chunk);
    is_sort = is_chunk_sorted(*stack_b);
    printf("testing first chunk size: %d, chunk median: %d, is chunk sorted: %d", chunk_size, median, is_sort);
    print_stack(*stack_a);
    print_stack(*stack_b);
    return;
}