#include "monty.h"


/**
  *subOpcode- Subtract two numbers
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void subOpcode(stackTvar **top, unsigned int line)
{

		stackTvar *sum; /* Pointer used for traversal & temporary storage */
		int diffe, countr;

		sum = *top; /* Set 'sum' to point to top of stack */
		for (countr = 0; sum != NULL; countr++)
			sum = sum->next; /* Traverse stack to countr number of nodes */
		if (countr < 2)
		{
			fprintf(stderr, variable(13), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		sum = *top; /* Reset 'sum' to point to top of stack */
		diffe = sum->next->n - sum->n;
		sum->next->n = diffe; /* Update value of 2nd node to be diffeference */
		*top = sum->next; /* Update top pointer to point to second node */
		free(sum); /* Free memory of prev top node */
}

/**
 * swapOpcode - Swaps the top two elements of the stack.
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void swapOpcode(stackTvar **top, unsigned int line)
{

		stackTvar *current; /* Pointer used for traversal */
		int lenVar = 0, sum; /* Variable used for countring & temporary storage */

		current = *top; /* Set 'current' to point to top of stack */
		while (current)
		{
			current = current->next;
			lenVar++;
		} /* Traverse stack to countr number of nodes */
		if (lenVar < 2)
		{
			fprintf(stderr, variable(8), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		current = *top; /* Reset 'current' to point to top of stack */
		sum = current->n; /* Store value of top node in 'sum' */
		current->n = current->next->n;
		current->next->n = sum;
}


/**
 * variable - prints message
 * @num: ninput
 * Return: str
 */
char *variable(int num)
{
	char *res;

	if (num <= 10)
		res = variable1(num);
	else
		res = variable2(num);
	return (res);
}

/**
 * variable1 - prints message
 * @num: ninput
 * Return: str
 */
char *variable1(int num)
{
	char *strrr;

	if (num == 0)
		strrr = "USAGE: monty file\n";
	else if (num == 1)
		strrr = "Error: Can't open file %s\n";
	else if (num == 2)
		strrr = "L%u: usage: push integer\n";
	else if (num == 3)
		strrr = "L%u: unknown instruction %s\n";
	else if (num == 4)
		strrr = "Error: malloc failed\n";
	else if (num == 5)
		strrr = "%d\n";
	else if (num == 6)
		strrr = "L%d: can't pint, stack empty\n";
	else if (num == 7)
		strrr = "L%u: can't pop an empty stack\n";
	else if (num == 8)
		strrr = "L%d: can't swap, stack too short\n";
	else if (num == 9)
		strrr = "L%d: can't add, stack too short\n";
	else if (num == 10)
		strrr = "L%u: can't pchar, stack empty\n";

	return (strrr);
}
