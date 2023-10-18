#include "monty.h"
/**
  *sub - Subtraction.
  *
  *@head: Top of the stack.
  *
  *@number: line_number.
  *
  *Return: no return
 */
void sub(stack_t **head, unsigned int number)
{
	stack_t *aux;
	int suspectCount, Numnodes;

	aux = *head;
	for (Numnodes = 0; aux != NULL; Numnodes++)
		aux = aux->next;
	if (Numnodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	suspectCount = aux->next->n - aux->n;
	aux->next->n = suspectCount;
	*head = aux->next;
	free(aux);
}
