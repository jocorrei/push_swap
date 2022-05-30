#include "../includes/push_swap.h"

node* init_stack_a(int argc, char **argv)
{
    node* head = NULL;
	node* temp = NULL;
	node* p = NULL;

	int i = 0;
    while (i < argc)
    {
        temp = (node*)malloc(sizeof(node*));
		temp->value = argv[++i];
        temp->next = NULL;
		if (!head)
            head = temp;
        else
        {
            p = head;
            while (p->next)
			{
				p->prev = p;
                p = p->next;
			}
            p->next = temp;
        }
    }
    return head;
}

node* init_stack_b(int size) {
	node* head = NULL;
	node* temp = NULL;
	node* p = NULL;
	int i;

	i = 0;
	while (i < size)
	{
		temp = (node*)malloc(sizeof(node*));
		temp->value = NULL;
		temp->next = NULL;
		if(!head)
			head = temp;
		else
		{
			p = head;
            while (p->next)
                p = p->next;
            p->next = temp;
		}
		i++;
	}
	return head;
}

void printLinkedList(node* head)
{
	node* p = head;

	while (p->next)
	{
		ft_printf("%s\n", p->value);
		p = p->next;
	}
	return ;
}

int main(int argc, char **argv)
{
	node *head_a = NULL;
	node *head_b = NULL;
	argc = check_args(argc, argv);

	if (argc)
	{	
		head_a = init_stack_a(argc, argv);
		head_b = init_stack_b(argc);
		swap_a(head_a);
		swap_b(head_b);
		swap_s(head_a, head_b);
		printf("\nstack_a:\n");
    	printLinkedList(head_a);
		printf("\nstack_b:\n");
		printLinkedList(head_b);
	}
	return 0;
}