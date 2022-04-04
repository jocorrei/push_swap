#include "../includes/push_swap.h"

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
    
    head = createLinkedList(argc, argv);
    printLinkedList(head);
	return 0;
}