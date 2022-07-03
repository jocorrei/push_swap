#include "../includes/push_swap.h"

node* list_copy(node* head, int chunk)
{
    node* curr;
    node* copy = NULL;
    node* tail = NULL;

    curr = head;
    while (curr->chunk != chunk && curr != NULL)
        curr = curr->next;
    while (curr != NULL && curr->chunk == chunk)
    {
        if (copy == NULL)
        {
            copy = (node*)malloc(sizeof(node));
            copy->value = curr->value;
            copy->next = NULL;
            tail = copy;
        }
        else 
        {
            tail->next = (node*)malloc(sizeof(node));
            tail = tail->next;
            tail->value = curr->value;
            tail->next = NULL;
        }
        curr = curr->next;
    }
    return copy;
}