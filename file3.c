#include "monty.h"


/**
 * pushOpcode - add node to the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void pushOpcode(stackTvar **top, unsigned int line)
{

		int n, j = 0, custom_flag = 0; /* Variables used for processing argument */

		if (interpret.arg)
		{
			if (interpret.arg[0] == '-') /* see argument starts with a negative sign */
				j++; /* Increment 'j' to skip the negative sign in further processing */
			/*  iterate over characters in argument until end ('\0') is reached */
			for (; interpret.arg[j] != '\0'; j++)
			{
				if (interpret.arg[j] > 57 || interpret.arg[j] < 48)
					custom_flag = 1; /* Set 'custom_flag' to indicate a non-integer value */
			}
			if (custom_flag == 1)
			{
				fprintf(stderr, variable(2), line);
				fclose(interpret.file); /* Close the file */
				free(interpret.content); /* Free memory allocated for line content */
				freeListFunc(*top); /* Free memory allocated for stack */
				exit(EXIT_FAILURE); /* rid program with a failure status */
			}
		}
		else
		{
			fprintf(stderr, variable(2), line);
			fclose(interpret.file);
			free(interpret.content);
			freeListFunc(*top);
			exit(EXIT_FAILURE);
		}
		n = atoi(interpret.arg);
		if (interpret.lifi == 0)
			insertNodeFunc(top, n); /* Insert integer into stack (lifo mode) */
		else
			enqueueFunc(top, n);
}

/**
  *rotateOpcode- This is to rotate the stack to the top
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotateOpcode(stackTvar **top,  __attribute__((unused)) unsigned int line)
{
		stackTvar *temp = *top, *sum;

		if (*top == NULL || (*top)->next == NULL)
		{
			return; /* stack is empty or contains only one element */
			/* no need to perform the swap */
		}
		sum = (*top)->next; /* Store second node of stack in 'sum' */
		sum->prev = NULL; /* Set 'prev' pointer of 'sum' to NULL */
		while (temp->next != NULL)
		{
			temp = temp->next; /* Traverse to last node of stack using 'temp' */
		}
		temp->next = *top;
		(*top)->next = NULL; /* Set 'next' pointer of new top node to NULL */
		(*top)->prev = temp; /* Set 'prev' pointer of new top node to 'temp' */
		(*top) = sum; /* Update top pointer to point to new top node */
}

/**
  *rotateBottomFunc- Rotates the stack elements towards the bottom
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotateBottomFunc(stackTvar **top,
				__attribute__((unused)) unsigned int line)
{
		stackTvar *duplicate; /* Pointer used for duplicate node traversal */

		duplicate = *top; /* Set 'duplicate' to point to top of stack */
		if (*top == NULL || (*top)->next == NULL)
		{
			return;
		}
		while (duplicate->next)
		{
			duplicate = duplicate->next;
		}
		duplicate->next = *top;
		duplicate->prev->next = NULL; /* Set 'next' pointer of prev node to NULL */
		duplicate->prev = NULL; /* Set 'prev' pointer of duplicate node to NULL */
		(*top)->prev = duplicate;
		(*top) = duplicate; /* Update top pointer to point to duplicate node */
}

/**
 * stackTopFunc - Prints the top element of the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void stackTopFunc(stackTvar **top, unsigned int line)
{

	/* line is used to suppress "unused variable" warning for 'top' parameter */
	(void)top;
	/* line is used to suppress  "unused variable" warning for 'line' parameter */
	(void)line;
	/* Set 'lifi' field of 'interpret' struct to 0 */
	interpret.lifi = 0;
}
