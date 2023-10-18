#include "monty.h"

/**
 * print_character - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @Opcode_line: Interger representing the line number of of the opcode.
 */
void print_character(stack_t **stack, unsigned int Opcode_line)
{
	int asciiValue;

	if (stack == NULL || *stack == NULL)
		string_error(11, Opcode_line);

	asciiValue = (*stack)->n;
	if (asciiValue < 0 || asciiValue > 127)
		string_error(10, Opcode_line);
	printf("%c\n", asciiValue);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int asciiValue;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		asciiValue = temp->n;
		if (asciiValue <= 0 || asciiValue > 127)
			break;
		printf("%c", asciiValue);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
