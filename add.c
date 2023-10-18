#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 *
 * @head: Top of the stack.
 *
 * @number: line_number.
 *
 * Return: no return
*/
void add(stack_t **head, unsigned int number)
{
	stack_t *temp;
	int length = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n + temp->next->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}
