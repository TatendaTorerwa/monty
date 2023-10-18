#include "monty.h"
/**
 * swap - Adds the top two elements of the stack.
 *
 * @head: Top of the head.
 *
 * @number: line_number.
 *
 * Return: no return
*/
void swap(stack_t **head, unsigned int number)
{
	stack_t *temp;
	int length = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}
