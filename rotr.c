#include "monty.h"
/**
  *rotr- Rotates the stack to the bottom.
  *
  *@head: Top of the stack.
  *
  *@number: line_number.
  *
  *Return: no return
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int number)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
