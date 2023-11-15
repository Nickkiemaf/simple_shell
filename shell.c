#include "shell.h"
/**
 * main - entry point for the whoe program
 * @argc: argument count
 * @argv: argument variable, gets the name of shell program
 * @env: environment variable
 *
 * Return: Always 0 (Success), my Shell is perfect
 */
int main(int argc, char **argv)
{
	size_t buff;
	ssize_t numb;
	char *address = NULL;
	char *token[11];
	/*char **envp;*/
	char *prg = argv[0];

	buff = 0;

	(void)argc;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			mathail_print("$ ");

		numb = getline(&address, &buff, stdin);

		if (mathail_exit(address))
		{
			free(address);
			exit(EXIT_SUCCESS);
		}
		if (numb == EOF)
		{
			free(address);
			exit(EXIT_SUCCESS);
			/*mathail_print("\n");*/
		}
		/*tokenize the input command*/
		mathail_token(address, token);

		if (token[0] == NULL)
			continue;

		excve_command(token, prg);
		err_msg(prg, NULL, 0);
	}
	free(address);
	return (0);
}
