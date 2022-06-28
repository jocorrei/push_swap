#include "../includes/push_swap.h"

void print_stack(node* head)
{
	node* p = head;

	ft_printf("\n list: \n");
	while (p)
	{
		ft_printf("%s\n", p->value);
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
    int cnt = 0;
    node *current_node = stack;
    while ( current_node != NULL) {
        cnt++;
        current_node = current_node->next;
    }
	return(cnt);
}

int is_sorted(node *stack)
{
	node* p;
	int value;

	value = ft_atoi(stack->value);
	p = stack;
	while (p->next)
	{
		p = p->next;
		if (ft_atoi(p->value) <= value)
			return 0;
		value = ft_atoi(p->value);
	}
	return 1;
}