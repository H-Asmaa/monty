#include "monty.h"
/**
 * pushNode - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void pushNode(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = createNode(command.number);
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
		return;
	}
	node->prev = *stack;
	(*stack)->next = node;
	*stack = node;
}
/**
 * pallStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void pallStack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
 * pintStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void pintStack(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * popStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void popStack(stack_t **stack, unsigned int line_number)
{
	stack_t *pop;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop = *stack;
	*stack = (*stack)->prev;
	free(pop);
}
/**
 * popStack - check the code
 * @stack: first variable
 * @line_number: Second variable
 * Return: void.
 */
void swapStack(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;
}
