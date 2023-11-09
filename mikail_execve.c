#include "shell.h"
/* excve_command - function to exceute command
 * @token - input command
 * @env[]: enviroment variable
 * @prg: argument count
 */

void excve_command(char **token, char *prg)
{
	pid_t child_pid;
	int num_exve, status, status_code;
	char *path = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		err_msg(prg, token, 1);
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0)
	{
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
