#include "monty.h"


/**
 * variable2 - prints message
 * @num: ninput
 * Return: str
 */
char *variable2(int num)
{
	char *strrr;

	if (num == 11)
		strrr = "%c\n";
	else if (num == 12)
		strrr = "L%u: can't pchar, value out of range\n";
	else if (num == 13)
		strrr = "L%d: can't sub, stack too short\n";
	else if (num == 14)
		strrr = "L%d: can't div, stack too short\n";
	else if (num == 15)
		strrr = "L%u: division by zero\n";
	else if (num == 16)
		strrr = "L%d: can't mul, stack too short\n";
	else if (num == 17)
		strrr = "L%d: can't mod, stack too short\n";
	else if (num == 18)
		strrr = "L%u: division by zero\n";
	else if (num == 19)
		strrr = " \n\t\r";
	else if (num == 20)
		strrr = "push";
	return (strrr);
}

/**
 * insertNodeFunc - Insert a node at the beginning of the linked list
 * @top: Pointer to the head of the linked list
 * @n: Value to be stored in the new node
*/
void insertNodeFunc(stackTvar **top, int n)
{
		stackTvar *new, *sum; /* set current top of the stack to 'sum' variable */

		sum = *top;
		new = malloc(sizeof(stackTvar));
		if (new == NULL)
		{
			printf("Error\n");
			exit(0); /* rid program if memory allocation failed */
		}
		if (sum)
			sum->prev = new;
		new->n = n; /* Set value of new node to given value 'n' */
		new->next = *top; /* next pointer of new node to point,current top stack */
		new->prev = NULL;
		*top = new; /* Update top of stack to point to new node */
}



busTvar interpret = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: The location of the Monty file
* Return: 0 on success
*/
int main(int argc, char *argv[])
{

		char *content; /* Variable to store content of each line read from file */
		FILE *new_file; /* Pointer to file to be opened */
		size_t size = 0; /* set size for getline() function */
		ssize_t read_line = 1; /* Number of characters read by getline() function */
		stackTvar *new_stack = NULL; /* Pointer to stack structure */
		unsigned int line = 0; /* Countrer to keep track of the line number */

		if (argc != 2)
		{
			fprintf(stderr, "%s", variable(0));
			exit(EXIT_FAILURE); /* rid program with a failure status */
		}
		new_file = fopen(argv[1], "r");
		interpret.file = new_file;
		if (!new_file)
		{
			fprintf(stderr, variable(1), argv[1]);
			exit(EXIT_FAILURE); /* rid program with a failure status */
		}
		while (read_line > 0)
		{
			content = NULL; /* Reset content pointer for each line read */
			read_line = getline(&content, &size, new_file);
			interpret.content = content;
			line++; /* Increment the line number countrer */
			if (read_line > 0)
			{
				executeMontyProgFunc(content, &new_stack, line, new_file);
			}
			free(content); /* Free memory allocated by getline() for content of line */
		}
		freeListFunc(new_stack); /* Free memory allocated for stack structure */
		fclose(new_file); /* Close the file */
return (0); /* Return 0 to indicate successful program execution */
}


/**
* freeListFunc - Frees a doubly linked list
* @top: Pointer of head of the list
*/
void freeListFunc(stackTvar *top)
{
		stackTvar *sum;

		sum = top;
		while (top)
		{
			sum = top->next;
			free(top);
			top = sum;
		}
}

