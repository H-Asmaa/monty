#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct store_s - check the code
 * @data: data
 * @val: val
 * @number: number
 * Description: store_t
 * for stack, queues, LIFO, FIFO
 */
typedef struct store_s
{
	char *data;
        char *val;
        int number;
} store_t;
extern store_t command;

/**
 * functions prototypes
*/
void pushNode(stack_t **stack, unsigned int line_number);
void pallStack(stack_t **stack, unsigned int line_number);
void pintStack(stack_t **stack, unsigned int line_number);
void popStack(stack_t **stack, unsigned int line_number);
stack_t *createNode(int data);
void slaughterLine(char *line);
void free_dlistint(stack_t *head);
void readLine(FILE *f, instruction_t *Dictionnary);
int checkNumber();
void Error(FILE *f, stack_t *top, int lineNumber, char *errorStr);
void swapStack(stack_t **stack, unsigned int line_number);
void addStack(stack_t **stack, unsigned int line_number);
void nopStack(stack_t **stack, unsigned int line_number);
void subStack(stack_t **stack, unsigned int line_number);
void divStack(stack_t **stack, unsigned int line_number);
#endif
