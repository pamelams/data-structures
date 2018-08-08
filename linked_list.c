#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int item;
	struct node *next;	
} node;

node* create_linked_list()
{
	return NULL;
}

node* add_node(node *head, int item)
{
	node *new_node = (node*)malloc(sizeof(node));

	new_node->item = item;
	new_node->next = head;
	head = new_node;

	return head;
}

node* search(node *head, int item)
{
	node *current = head;

	while(current != NULL)
	{
		if(current->item == item)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

node* remove_node(node *head, int item)
{
	node *previous = NULL;
	node *current = head;

	while(current != NULL && current->item != item)
	{
		previous = current;
		current = current->next;
	}	
	if(current == NULL)
	{
		return head;
	}
	if(previous == NULL)
	{
		head = current->next;
	}
	else
	{
		previous->next = current->next;
	}
	free(current);

	return head;
}

int is_empty(node *head)
{
	return (head == NULL);
}

void print_linked_list(node *head)
{
	node *current = head;

	while(current != NULL)
	{
		printf("%d\n", current->item);
		current = current->next;
	}
}
