#include "monty.h"
/**
 * add_node - Add node to the head stack.
 *
 * @head: Top of the stack.
 *
 * @n: new_value.
 *
 * Return: no return
*/
void add_node(stack_t **head, int n)
{

	stack_t *newnode, *aux;

	aux = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
}
