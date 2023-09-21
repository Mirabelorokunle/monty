#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stackStrct - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stackStrct
{
	int n;
	struct stackStrct *prev;
	struct stackStrct *next;
} stackTvar;

/**
 * struct instructionStrct - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instructionStrct
{
	char *opcode;
	void (*f)(stackTvar **stack, unsigned int line_number);
} instructionTvar;

/**
 * struct busStrctinfo - Structure for holding program variables and arguments.
 * @arg: Value argument
 * @file: Pointer to monty file
 * @content: Line content
 * @lifi: Flag to change between stack and queue behavior
 * Description: Structure that carries values and flags throughout the program
 */
typedef struct busStrctinfo
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  busTvar;
extern busTvar interpret;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void pushOpcode(stackTvar **top, unsigned int number);
void pallOpcode(stackTvar **top, unsigned int number);
void pintOpcode(stackTvar **top, unsigned int number);
int executeMontyProgFunc(char *input, stackTvar **data,
		unsigned int line, FILE *file);
void freeListFunc(stackTvar *top);
void popOpcode(stackTvar **top, unsigned int line);
void swapOpcode(stackTvar **top, unsigned int line);
void addTopFunc(stackTvar **top, unsigned int line);
void nopOpcode(stackTvar **top, unsigned int line);
void subOpcode(stackTvar **top, unsigned int line);
void divideTop2Items(stackTvar **top, unsigned int line);
void mulOpcode(stackTvar **top, unsigned int line);
void modOpcode(stackTvar **top, unsigned int line);
void pcharOpcode(stackTvar **top, unsigned int line);
void printStrFunc(stackTvar **top, unsigned int line);
void rotateOpcode(stackTvar **top, unsigned int line);
void rotateBottomFunc(stackTvar **top,
		__attribute__((unused)) unsigned int line);
void insertNodeFunc(stackTvar **top, int n);
void enqueueFunc(stackTvar **top, int n);
void queueOpcodeFunc(stackTvar **top, unsigned int line);
void stackTopFunc(stackTvar **top, unsigned int line);

char *variable(int num);
char *variable1(int num);
char *variable2(int num);
#endif /* MONTY_H */
