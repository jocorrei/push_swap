#include "../includes/push_swap.h"

int check_args(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        while (argv[i][j])
        {   
            if (ft_isdigit(argv[i][j]))
                j++;
            else
            {
                ft_printf("Error: Argument is not a digit");
                return 0;
            }
        }
        i++;
    }
    return 1;
}

// char **organize_args(char **args)
// {

// }

node* createLinkedList(int argc, char **argv)
{
    node* head = NULL;
	node* temp = NULL;
	node* p = NULL;
	int i = 1;

    while (i < argc)
    {
        temp = (node*)malloc(sizeof(node*));
        temp->value = argv[i++];
        temp->next = NULL;
        if (!head)
            head=temp;
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
	free(head);
	return ;
}


int main(int argc, char **argv)
{
    node *head = NULL;
    
    if (!check_args(argc, argv))
        return 0;
    head = createLinkedList(argc, argv);
    printLinkedList(head);
	return 0;
}