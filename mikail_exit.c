#include "shell.h"
/*
 * mathail_exit - function to exit the terminal
 * @input: argument
 */
int mathail_exit(char *input)
{
	if (_strncmp(input, "exit", 4) == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

