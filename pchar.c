#include "monty.h"
/**
 * print_char - Prints the char at the top of the stack,
 * followed by a new line.
 *
 * @head: Top of the stack.
 *
 * @number: line_number.
 *
 * Return: no return
*/
void print_char(stack_t **head, unsigned int number)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
