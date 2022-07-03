#include "../includes/push_swap.h"


// REMOVE PRINT_F BEFORE GET FUCKED
void print_stack(node* head)
{
	node* p;

    p = head;
	printf("list: \n");
	while (p)
	{
		printf("value: %d, chunk: %d\n", p->value, p->chunk);
		p = p->next;
	}
	return ;
}

void free_stack(node** head)
{
   node *tmp;

   while (*head != NULL)
    {
       tmp = *head;
       *head = (*head)->next;
       free(tmp);
	   tmp = NULL;
    }
	return ;
}

int count_stack(node *stack) 
{
    int cnt;
    node *curr;
    
    cnt = 0;
    curr = stack;
    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
	return(cnt);
}

int is_sorted(node *stack)
{
	node* p;
	int value;

	value = stack->value;
	p = stack;
	while (p->next)
	{
		p = p->next;
		if (p->value <= value)
			return 0;
		value = p->value;
	}
	return 1;
}