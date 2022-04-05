#include "../includes/push_swap.h"

int check_args(int argc, char **argv)
{
    int i;

	i = 1;
	if (argc <= 1)
		return 0;
	if (argc == 2)
    {
        if (ft_str_is_numbers(argv[1]))
            return 1;
        else
            return 0;
    }
    if (argc > 2)
    {
        while (argv[i])
        {
			if (ft_str_is_numbers(argv[i]))
				i++;
			else
				return 0;
        }
    }
	return 1;
}

node* createLinkedList(int argc, char **argv)
{
    node* head = NULL;
	node* temp = NULL;
	node* p = NULL;
	int i = 0;

    while (i < argc)
    {
        temp = (node*)malloc(sizeof(node*));
        temp->value = argv[i++];
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
		printf("%s\n", p->value);
		p = p->next;
	}
	printf("%s\n", p->value);
	return ;
}

int main(int argc, char **argv)
{
	node *head = NULL;

	// if (!check_args(argc, argv))
	// {
	// 	// ERROR should be returned to stder not stdin
	// 	printf("ERROR");
	// 	return 0;
	// }		
	// if (argc == 2)
	// 	argv = ft_split(argv[1], ' ');

	if (argc <= 1)
		return 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc > 2)
		argv = &argv[1];
	// take off argc as argument of the createLinkedList (calculate the lenght inside the functions)
	head = createLinkedList(argc, argv);
    printLinkedList(head);
	return 0;
}