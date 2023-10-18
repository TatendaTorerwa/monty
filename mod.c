#include "monty.h"
/**
 * mod - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @head: Top of the stack.
 *
 * @number: line_number.
 *
 * Return: no return
*/
void mod(stack_t **head, unsigned int number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = temp->next->n % temp->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}
