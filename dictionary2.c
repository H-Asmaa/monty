#include "monty.h"
/**
 * addStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void addStack(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *tmp;
	int sum = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	sum = top->n + top->prev->n;
	tmp = top->prev;
	top->prev = tmp->prev;
	top->n = sum;
	free(tmp);
}
void nopStack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
