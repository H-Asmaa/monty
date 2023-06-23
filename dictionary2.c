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
/**
 * nopStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void nopStack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * subStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void subStack(stack_t **stack, unsigned int line_number)
{
	int num1, num2;
	stack_t *temp;

    if (*stack == NULL || (*stack)->prev == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    num1 = (*stack)->n;
    num2 = (*stack)->prev->n;
    (*stack)->prev->n = num2 - num1;
    temp = *stack;
    *stack = (*stack)->prev;
    (*stack)->next = NULL;
    free(temp);
}
/**
 * divStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void divStack(stack_t **stack, unsigned int line_number)
{
	int num1, num2;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->prev->n;
	(*stack)->prev->n = num1 / num2;
	tmp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(tmp);
}
