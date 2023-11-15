#include "shell.h"
/**
 * execute - function to execute
 * @token: input
 * prg: variable
 **/
void execute(char **token, char *prg)
{
	int num_exve;
	char *path = NULL;

	if (token[0][0] == '/')
	{
		num_exve = execve(token[0], token, environ);
		err_msg(prg, token, 2);
	}
	else
	{

		path = get_path(token[0]);

		if (path == NULL)
		{
			err_msg(prg, token, 3);
			exit(127);
		}

		num_exve = execve(path, token, environ);
		if (num_exve == -1)
		{
			err_msg(prg, token, 3);
			exit(127);
		}
	}
}

