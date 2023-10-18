#include "monty.h"
/**
 * print_str - Prints the string starting at the top of the stack,
 * followed by a new.
 *
 * @head: Top of the stack.
 *
 * @number: line_number.
 *
 * Return: no return
*/
void print_str(stack_t **head, unsigned int number)
{
	stack_t *temp;
	(void)number;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
