#include "shell.h"
/**
 * excve_command - function to exceute command
 * @token - input command
 * @env[]: enviroment variable
 * @prg: argument count
 **/

void excve_command(char **token, char *prg)
{
	pid_t child_pid;
	int status, status_code;

	child_pid = fork();
	if (child_pid == -1)
	{
		err_msg(prg, token, 1);
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0)
	{
		execute(token, prg);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) != 0)
		{
			status_code = WEXITSTATUS(status);
			if (status_code == 127)
			{
				exit(127);
			}

			if (status_code == 2)
			{
				exit(2);
			}
		}
	}
}

