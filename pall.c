#include "monty.h"
/**
 * pall - prints the stack.
 *
 * @head: Top of the stack.
 *
 * @totalcount: no used.
 *
 * Return: no return
*/
void pall(stack_t **head, unsigned int totalcount)
{
	stack_t *temp;
	(void)totalcount;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
