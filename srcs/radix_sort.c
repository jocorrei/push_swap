#include "../includes/push_swap.h"

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