#include "shell.h"
/*
 * mathail_token - function to tokenize the input
 * @address: pointer to arument and command
 * @token: the totknized string
 */
void mathail_token(char *address, char **token)
{
	int k = 0;

	token[k] = tokenize(address, " \n");

	while (token[k])
	{
		token[++k] = tokenize(NULL, " \n");
	}
	token[k] = NULL;
}

