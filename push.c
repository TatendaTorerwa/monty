#include "monty.h"
/**
 * push - add node to the stack.
 *
 * @head: Top of the stack.
 *
 * @totalcount: line_number.
 *
 * Return: no return
*/
void push(stack_t **head, unsigned int totalcount)
{
	int p, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", totalcount);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", totalcount);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	p = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, p);
	else
		addqueue(head, p);
}
