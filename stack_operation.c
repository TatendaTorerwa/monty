#include "monty.h"

/**
 * stack_multiply - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNo: Interger representing the line number of of the opcode.
 */
void stack_multiply(stack_t **stack, unsigned int lineNo)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lineNo, "mul");

	(*stack) = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * stack_modulo - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNo: Interger representing the line number of of the opcode.
 */
void stack_modulo(stack_t **stack, unsigned int lineNo)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, lineNo, "mod");


	if ((*stack)->n == 0)
		more_error(9, lineNo);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
