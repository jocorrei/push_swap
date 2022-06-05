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
		temp->value = argv[i];
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


void printLinkedList(node* head)
{
	node* p = head;

	printf("\n list: \n");
	while (p)
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

int count(node *head) {
    int cnt = 0;
    node *current_node = head;
    while ( current_node != NULL) {
        cnt++;
        current_node = current_node->next;
    }
return(cnt);
}

int main(int argc, char **argv)
{
	node *head_a = NULL;
	node *head_b = NULL;
	int test = 0;
	argc = check_args(argc, argv);

	if (argc)
	{	
		head_a = init_stack_a(argc, argv);
		push_b(&head_a, &head_b);
		push_b(&head_a, &head_b);
		push_b(&head_a, &head_b);
		push_b(&head_a, &head_b);
		swap_b(head_b);
		push_a(&head_a, &head_b);
		rotate_b(&head_b);
		rotate_a(&head_a);
		swap_s(head_a, head_b);
		rev_rotate_a(&head_a);
		rev_rotate_b(&head_b);
		test = count(head_a);
		printf("\ncounting linked list nodes: %d", test);
		printf("\nstack_a:");
    	printLinkedList(head_a);
		printf("\nstack_b:");
		printLinkedList(head_b);
		freeList(head_a);
		// freeList(head_b);
	}
	return 0;
}