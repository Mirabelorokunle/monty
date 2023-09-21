#include "monty.h"


/**
 * pintOpcode - prints the topPrints the top element of the stack
 * @top: Pointer to the stack
 * @line: Line number of the command
*/
void pintOpcode(stackTvar **top, unsigned int line)
{

		if (*top == NULL)
		{
			fprintf(stderr, variable(6), line);
			fclose(interpret.file); /* Close the file */
			free(interpret.content); /* Free memory allocated for line content */
			freeListFunc(*top); /* Free the memory allocated for the stack */
			exit(EXIT_FAILURE); /* rid program with a failure */
		} /* Print value (integer) stored in top node of stack */
		printf("%d\n", (*top)->n);
}

/**
 * popOpcode - Print from the top of the stack
 * @top: Pointer to the stack
 * @line: Line number in the file
*/
void popOpcode(stackTvar **top, unsigned int line)
{

		stackTvar *current; /* Pointer to traverse the stack */

		if (*top == NULL)
		{
			fprintf(stderr, variable(7), line);
			fclose(interpret.file); /* Close the file */
			free(interpret.content); /* Free memory allocated for line content */
			freeListFunc(*top); /* Free memory allocated for stack */
			exit(EXIT_FAILURE); /* rid program with a failure status */
		}
		current = *top; /* Set 'current' to point to top of stack */
		*top = current->next; /* Update top of stack to next node */
		free(current); /* Free memory allocated for prev top node */
}

/**
 * printStrFunc - prints the string starting at the top of the stack,
 * followed by a new
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void printStrFunc(stackTvar **top, unsigned int line)
{
		stackTvar *current; /* Pointer to traverse stack */
		(void)line; /* Silence compiler warning about an unused variable 'line' */

		current = *top; /* Set 'current' to point to the top of the stack */
		while (current)
		{
			if (current->n > 127 || current->n <= 0)
			{
				break; /* Break loop if value in current node is out of range */
			}
			printf("%c", current->n);
			current = current->next; /* Move 'current' to next node in stack */
		}
}
