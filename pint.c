#include "monty.h"
/**
 * pint - prints the top.
 *
 * @head: Top of the stack.
 *
 * @totalcount: line_number.
 *
 * Return: no return
*/
void pint(stack_t **head, unsigned int totalcount)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", totalcount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
