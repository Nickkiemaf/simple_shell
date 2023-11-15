#include "shell.h"
/**
 * mathail_print - function to print funtion terminal
 * @jb_strings: inputs from the terminal
 */
void mathail_print(char *jb_strings)
{
	int len;

	len = 0;
	while (jb_strings[len] != '\0')
		len++;
	write(STDOUT_FILENO, jb_strings, len);
}

