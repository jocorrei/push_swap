#include "../includes/push_swap.h"

static void sorted_insert(node** head, node* new_node)
{
    node temp;
    node* curr;

    curr = &temp;
    temp.next = *head;
    while (curr->next != NULL && curr->next->value < new_node->value) 
        curr = curr->next;
    new_node->next = curr->next;
    curr->next = new_node;
    *head = temp.next;
}
 
static void insert_sort(node** head)
{
    node* temp;
    node* curr;
    node* next;

    temp = NULL;
    curr = *head;
    while (curr != NULL)
    {
        next = curr->next;
        sorted_insert(&temp, curr);
        curr = next;
    } 
    *head = temp;
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