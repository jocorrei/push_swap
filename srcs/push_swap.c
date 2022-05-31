#include "../includes/push_swap.h"

node* init_stack_a(int argc, char **argv)
{
    node* head = NULL;
	node* temp = NULL;
	node* p = NULL;

	int i = 0;
    while (i < argc)
    {
        temp = (node*)malloc(sizeof(node*)*2 + sizeof(char *));
		temp->prev = NULL;
		temp->value = argv[++i];
        temp->next = NULL;
		if (!head)
            head = temp;
        else
        {
            p = head;
            while (p->next)
                p = p->next;
            p->next = temp;
			temp->prev = p;
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
		temp = (node*)malloc(sizeof(node*)*2 + sizeof(char *));
		temp->prev = NULL;
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
			temp->prev = p;
		}
		i++;
	}
	return head;
}

void printLinkedList(node* head)
{
	node* p = head;

	printf("\n list: \n");
	while (p->next)
	{
		ft_printf("%s\n", p->value);
		p = p->next;
	}
	return ;
}

void freeList(node* head)
{
   node *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
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
		rotate_a(head_a);
		rotate_b(head_b);
		printf("\nstack_a:\n");
    	printLinkedList(head_a);
		printf("\nstack_b:\n");
		printLinkedList(head_b);
		freeList(head_a);
		freeList(head_b);
	}
	return 0;
}