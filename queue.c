#include "monty.h"
/**
 * queue - Prints the top.
 *
 * @head: The top of the queue.
 *
 * @number: line_number.
 *
 * Return: no return
*/
void queue(stack_t **head, unsigned int number)
{
	(void)head;
	(void)number;
	bus.lifi = 1;
}

/**
 * add_queue - Add node to the tail stack.
 *
 * @n: new_value.
 *
 * @head: Top of the stack.
 *
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *newnode, *aux;

	aux = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
	}
	newnode->n = n;
	newnode->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = newnode
;
		newnode
->prev = NULL;
	}
	else
	{
		aux->next = newnode
;
		newnode
->prev = aux;
	}
}
