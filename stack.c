#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int item;
	struct node *next;
} node;

typedef struct stack
{
	node *top;
} stack;

stack* create_stack()
{
	stack *new_stack = (stack*)malloc(sizeof(stack));

	new_stack->top = NULL;

	return new_stack;
}

int is_empty(stack *st)
{
	return(st->top == NULL);
}

void push(stack *st, int item)
{
	node *new_top = (node*)malloc(sizeof(node));

	new_top->item = item;
	new_top->next = st->top;
	st->top = new_top;
}

void pop(stack *st)
{
	node *current = st->top;

	if(is_empty(st))
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("%d ", st->top->item);
		st->top = st->top->next;
		free(current);
	}
}

int peek(stack *st)
{
	if(is_empty(st))
	{
		printf("Stack underflow\n");
		return -1;
	}
	else
	{
		return st->top->item;
	}
}
