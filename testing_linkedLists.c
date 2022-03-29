#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

node* createLinkedList(int size)
{
	node* head = NULL;
	node* temp = NULL;
	node* p = NULL;
	int i = 0;

	while (i < size)
    {
		temp = (node* )malloc(sizeof(node*));

		printf("enteder number: ");
		scanf("%d", &(temp->data));
		temp->next = NULL;

		if (head == NULL)
			head = temp;
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
		i++;
    }
	i++;
	return head;
}

void printLinkedList(node* head)
{
	node* p = NULL;

	p = head;

	while (p->next != NULL)
	{
		printf("%d", p->data);
		p++;
	}
	printf("%d", p->data);
	return ;
}

int main()
{
    int size = 0;
    node *head = NULL;

    printf("how many node?");
    scanf("%d", &size);
    head = createLinkedList(size);
	printLinkedList(head);
    return 0;
}