#include "monty.h"
store_t command;
/**
 * createNode - check the code
 * @data: first variable
 * Return: void.
 */
stack_t *createNode(int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = data;
	node->next = NULL;
	return (node);
}
/**
 * free_dlistint - check the code
 * @line: first variable
 * Return: void.
 */
void slaughterLine(char *line)
{
	command.data = strtok(line, " ");
	if (strcmp(command.data, "push") == 0)
	{
		command.val = strtok(NULL, " ");
	}
}
/**
 * free_dlistint - check the code
 * @head: first variable
 * Return: void.
 */
void free_dlistint(stack_t *head)
{
	stack_t *p;

	while (head != NULL)
	{
		p = head;
		head = head->prev;
		free(p);
	}
	free(head);
}
/**
 * checkNumber - check the code
 * Return: void.
 */
int checkNumber()
{
	int checkNumber;
	int j;

	j = 0;
	while (command.val[j] != '\0')
	{
		if ((command.val[j] >= 48 && command.val[j] <= 57) || command.val[j] == '-')
		{
			checkNumber = 1;
			j++;
		}
		else
		{
			checkNumber = 0;
			break;
		}
		j++;
	}
	return (checkNumber);
}
/**
 * Error - check the code
 * @f: first variable
 * @top: second
 * @lineNumber: third
 * @errorStr: forth
 * Return: void.
 */
void Error(FILE *f, stack_t *top, int lineNumber, char *errorStr)
{
	fprintf(stderr, "L%u: %s", lineNumber, errorStr);
	free_dlistint(top);
	fclose(f);
	exit(EXIT_FAILURE);
}
/**
 * main - check the code
 * @f: first variable
 * @Dictionnary: Second variable
 * Return: void.
 */
void readLine(FILE *f, instruction_t *Dictionnary)
{
	stack_t *top = NULL;
	char line[100], *noSpace;
	unsigned int lineNumber = 0;
	int checkNum, i = 0;

	while (fgets(line, sizeof(line), f))
	{
		command.val = NULL;
		lineNumber++;
		line[strcspn(line, "\n")] = '\0';
		noSpace = line;
		while (*noSpace == ' ')
			noSpace++;
		if (*noSpace != '\0' && *noSpace != '#')
		{
			slaughterLine(noSpace);
			i = 0;
			while (Dictionnary[i].opcode != NULL)
			{
				if (strcmp(command.data, Dictionnary[i].opcode) == 0)
				{
					if (strcmp(command.data, "push") == 0)
					{
						if (command.val == NULL)
							Error(f, top, lineNumber, "usage: push integer");
						checkNum = checkNumber();
						if (checkNum == 1)
						{
							command.number = atoi(command.val);
							Dictionnary[i].f(&top, lineNumber);
							break;
						}
						else
							Error(f, top, lineNumber, "usage: push integer");
					}
					else
					{
						Dictionnary[i].f(&top, lineNumber);
						break;
					}
				}
				i++;
			}
		}
		if (Dictionnary[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, command.data);
			free_dlistint(top);
			fclose(f);
			exit(EXIT_FAILURE);
		}
	}
	free_dlistint(top);
}
/**
 * main - check the code
 * @argc: first variable
 * @argv: Second variable
 * Return: void.
 */
int main(int argc, char *argv[])
{
	instruction_t Dictionnary[] =
		{
			{"push", pushNode},
			{"pall", pallStack},
			{"pint", pintStack},
			{"pop", popStack},
			{"swap", swapStack},
			{"add", addStack},
			{"nop", nopStack},
			{"sub", subStack},
			{"div", divStack},
			{NULL, NULL}};
	FILE *f;

	if (argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s': ", argv[1]);
		exit(EXIT_FAILURE);
	}
	readLine(f, Dictionnary);
	fclose(f);
	return (0);
}
