#include "../includes/push_swap.h"

node* init_stack_a(int argc, char **argv)
{
    node* head = NULL;
	node* temp = NULL;
	node* p = NULL;

	int i = 0;
    while (++i < argc)
    {
        temp = (node*)malloc(sizeof(node));
		temp->prev = NULL;
		temp->value = ft_atoi(argv[i]);
        temp->next = NULL;
		if (!head)
            head = temp;
        else
        {
            p = head;
            while (p->next)
                p = p->next;
            p->next = temp;
			p->next->prev = p;
        }
    }
    return head;
}

int main(int argc, char **argv)
{
	node *head_a = NULL;
	node *head_b = NULL;
	argc = check_args(argc, argv);

	if (argc)
	{	
		head_a = init_stack_a(argc, argv);
		if (is_sorted(head_a))
			return 0;
		if (count_stack(head_a) <= 5)
			sort_small(&head_a, &head_b);
		printf("\nstack_a:");
    	print_stack(head_a);
		printf("\nstack_b:");
		print_stack(head_b);
		free_stack(head_a);
	}
	return 0;
}