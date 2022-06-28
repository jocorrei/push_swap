#include "../includes/push_swap.h"

void print_stack(node* head)
{
	node* p;

    p = head;
	ft_printf("\n list: \n");
	while (p)
	{
		ft_printf("%d\n", p->value);
		p = p->next;
	}
	return ;
}

void free_stack(node* head)
{
   node *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

int count_stack(node *stack) 
{
    int cnt;
    node *current_node;
    
    cnt = 0;
    current_node = stack;
    while (current_node != NULL) {
        cnt++;
        current_node = current_node->next;
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