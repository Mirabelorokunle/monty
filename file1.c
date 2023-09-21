#include "monty.h"


/**
 * addTopFunc - adds the top two elements of the stack.
 * @top: Pointer to the stack
 * @line: Line number where the function is called
 *
 * Description: Adds the top two elements of the stack and updates the stack
*/
void addTopFunc(stackTvar **top, unsigned int line)
{
		stackTvar *current;
		int lenVar = 0, sum;

		current = *top;
		while (current)
		{
			current = current->next;
			lenVar++;
		}
		if (lenVar < 2)
		{
			fprintf(stderr, variable(9), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		current = *top;
		sum = current->n + current->next->n;
		current->next->n = sum;
		*top = current->next;
		free(current);
}


/**
 * divideTop2Items - Computes the quotient of the top two stack elements.
 * @top: Pointer to the stack
 * @line: Line number where the division operation is performed.
*/

void divideTop2Items(stackTvar **top, unsigned int line)
{
		stackTvar *current;
		int lenVar = 0, sum;

		current = *top;
		while (current)
		{
			current = current->next;
			lenVar++;
		}
		if (lenVar < 2)
		{
			fprintf(stderr, variable(14), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		current = *top;
		if (current->n == 0)
		{
			fprintf(stderr, variable(18), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		sum = current->next->n / current->n;
		current->next->n = sum;
		*top = current->next;
		free(current);
}

/**
 * queueOpcodeFunc - Prints the elements of the queue
 * @top: Pointer to the top of the stack
 * @line: line_number
 * Return: no return
*/
void queueOpcodeFunc(stackTvar **top, unsigned int line)
{
		(void)top;
		(void)line;
		interpret.lifi = 1;
}

/**
 * enqueueFunc - Adds an element to the queue
 * @top: Pointer to the front of the queue
 * @n: Element to be added
 * Return: no return
*/
void enqueueFunc(stackTvar **top, int n)
{
		stackTvar *new, *sum;

		sum = *top;
		new = malloc(sizeof(stackTvar));
		if (new == NULL)
		{
			printf("Error\n");
		}
		new->n = n;
		new->next = NULL;
		if (sum)
		{
			while (sum->next)
				sum = sum->next;
		}
		if (!sum)
		{
			*top = new;
			new->prev = NULL;
		}
		else
		{
			sum->next = new;
			new->prev = sum;
		}
}

/**
* executeMontyProgFunc - executes the opcode
* @data: Pointer
* @line: line_countrer
* @file: poiner to monty file
* @input: line input
* Return: no return
*/
int executeMontyProgFunc(char *input, stackTvar **data, unsigned int line,
						FILE *file)
{
		instructionTvar operations[] = {
			{"push", pushOpcode}, {"pall", pallOpcode}, {"pint", pintOpcode},
			{"pop", popOpcode},
			{"swap", swapOpcode},
			{"add", addTopFunc},
			{"nop", nopOpcode},
			{"sub", subOpcode},
			{"div", divideTop2Items},
			{"mul", mulOpcode},
			{"mod", modOpcode},
			{"pchar", pcharOpcode},
			{"pstr", printStrFunc},
			{"rotl", rotateOpcode},
			{"rotr", rotateBottomFunc},
			{"queue", queueOpcodeFunc},
			{"stack", stackTopFunc},
			{NULL, NULL}
			};
		unsigned int i = 0;
		char *op;

		op = strtok(input, " \n\t");
		if (op && op[0] == '#')
			return (0);
		interpret.arg = strtok(NULL, " \n\t");
		while (operations[i].opcode && op)
		{
			if (strcmp(op, operations[i].opcode) == 0)
			{       operations[i].f(data, line);
					return (0);
			}
			i++;
		}
		if (op && operations[i].opcode == NULL)
		{ fprintf(stderr, variable(3), line, op);
			fclose(file);
			free(input);
			freeListFunc(*data);
			exit(EXIT_FAILURE); }
		return (1);
}
