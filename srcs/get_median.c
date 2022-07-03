#include "../includes/push_swap.h"

static void sorted_insert(node** head, node* new_node)
{
    node dummy;
    node* current;

    current = &dummy;
    dummy.next = *head;
    while (current->next != NULL && current->next->value < new_node->value) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    *head = dummy.next;
}
 
static void insert_sort(node** head)
{
    node* result;
    node* current;
    node* next;

    result = NULL;
    current = *head;
    while (current != NULL)
    {
        next = current->next;
        sorted_insert(&result, current);
        current = next;
    } 
    *head = result;
}

int search_median(node *stack, int chunk)
{
    node *cpy;
    int size;
    int median;
    int i;

    cpy = list_copy(stack, chunk);
    insert_sort(&cpy);
    size = count_stack(cpy);
    i = -1;
    while (++i < (size/2))
        cpy = cpy->next;
    median = cpy->value;
    free_stack(&cpy);
    return median;
}