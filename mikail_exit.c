#include "shell.h"
/*
 * mathail_exit - function to exit the terminal
 * @input: argument
 */
int mathail_exit(const char *input)
{
	return (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't' && input[4] == '\n');
}
