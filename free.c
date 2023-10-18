#include "monty.h"
/**
* freeStack - Frees a doubly linked list.
*
* @head: Top of the stack.
*/
void freeStack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
