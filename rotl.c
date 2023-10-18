#include "monty.h"
/**
  *rotl- Rotates the stack to the top.
  *
  *@head: Top of the head.
  *
  *@number: line_number.
  *
  *Return: no return
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int number)
{
	stack_t *temp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = aux;
}
