#include "../includes/push_swap.h"

node* createLinkedList(int argc, char **argv)
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
                p = p->next;
            p->next = temp;
        }
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
	node *head = NULL;
	int k;
	int i;
	char **ptr;
	i = 1;
	k = 0;
	// TODO: refactor to a checker function
	if (argc <= 1)
		return 0;
	if (argc == 2)
	{
		ptr = ft_split(argv[1], ' ');
		while (ptr[k])
			argv[i++] = ptr[k++];
		argc = i;
	}
	if (!check_digit(argc, argv) || !check_repeted(argc, argv))
	{
		// ERROR should be returned to stder not stdin
		printf("ERROR");
		return 0;
	}
	head = createLinkedList(argc, argv);
    printLinkedList(head);
	return 0;
}