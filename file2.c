#include "monty.h"


/**
 * modOpcode - Computes the remainder of division for top stack elements
 * top element of the stack by the top element of the stack
 * @top: Pointer to the stack
 * @line: Current line number
*/
void modOpcode(stackTvar **top, unsigned int line)
{
		stackTvar *current; /* Pointer to traverse the stack */
		int lenVar = 0, sum;



		current = *top; /* Set 'current' to point to top of stack */
		while (current)
		{
			current = current->next; /* move 'current' to the next node in the stack */
			lenVar++; /* Increment the length countrer */
		}
		if (lenVar < 2)
		{
			fprintf(stderr, variable(17), line);
			fclose(interpret.file); /* Close the file */
			free(interpret.content); /* Free memory allocated for line content */
			freeListFunc(*top); /* free memory allocated for stack */
			exit(EXIT_FAILURE); /* rid program with a failure status */
		}
		current = *top; /* Reset 'current' to point to top of stack */
		if (current->n == 0)
		{
			fprintf(stderr, variable(15), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		sum = current->next->n % current->n;
		current->next->n = sum; /* Store result of modulo operation in 2nd element */
		*top = current->next; /* Update top of stack to 2nd element */
		free(current); /* Free memory allocated for prev top element */
}

/**
 * mulOpcode - Multiplication of the top two elements in the stack.
 * @top: Pointer to the stack
 * @line: Line number in the script
 * Return: no return
*/
void mulOpcode(stackTvar **top, unsigned int line)
{

		stackTvar *current; /* Pointer to traverse stack */
		int lenVar = 0, sum;

		current = *top; /* Set 'current' to point to the top of stack */
		while (current)
		{
			current = current->next; /* Move 'current' to next node in stack */
			lenVar++; /* Increment the length countrer */
		}
		if (lenVar < 2)
		{
			fprintf(stderr, variable(16), line);
			fclose(interpret.file); /* Close the file */
			free(interpret.content); /* Free memory allocated for line content */
			freeListFunc(*top); /* Free memory allocated for stack */
			exit(EXIT_FAILURE); /* rid program with a failure status */
		}
		current = *top; /* Reset 'current' to point to top of stack */
		sum = current->next->n * current->n;
		current->next->n = sum;
		*top = current->next; /* Update top of stack to second element */
		free(current); /* Free memory allocated for previous top element */
}

/**
  *nopOpcode- Absolutely nothing
  *@top: Pointer to the stack
  *@line: Line number in the script
 */
void nopOpcode(stackTvar **top, unsigned int line)
{
		(void) line; /* Silence ompiler warning about an unused variable 'line' */
		(void) top; /* Silence the compiler warning about an unused variable 'top' */
}

/**
 * pallOpcode - Prints the elements of the stack
 * @top: Pointer to the stack
 * @line: Line number in the script (unused)
*/
void pallOpcode(stackTvar **top, unsigned int line)
{
		stackTvar *current; /* Pointer to traverse stack */
		(void)line; /* Silence compiler warning about an unused variable 'line' */

		current = *top; /* Set 'current' to point to the top of stack */
		if (current == NULL)
			return; /* If stack is empty, return without performing further actions */
		while (current)
		{
			printf("%d\n", current->n); /* Print value of current node in stack */
			current = current->next; /* move 'current' to the next node in the stack */
		}
}

/**
 * pcharOpcode - Prints the char at the top of the stack,
 * followed by a new line
 * @top: Pointer to the Pointer to the top of the stack
 * @line: Line number in the script
*/
void pcharOpcode(stackTvar **top, unsigned int line)
{

		stackTvar *current; /* Pointer to traverse stack */

		current = *top; /* Set 'current' to point to top of stack */
		if (!current)
		{
			fprintf(stderr, variable(10), line);
			fclose(interpret.file); /* Close the file */
			free(interpret.content); /* free memory allocated for line content */
			freeListFunc(*top); /* Free memory allocated for stack */
			exit(EXIT_FAILURE); /* rid program with a failure status */
		}
		if (current->n > 127 || current->n < 0)
		{
			fprintf(stderr, variable(12), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		} /* Print character corresponding to value in top node of stack */
		printf(variable(11), current->n);
}

