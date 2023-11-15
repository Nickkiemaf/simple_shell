#include "shell.h"
/*
 * path_address - function that takes the path
 * @my_path:
 * @input: accepted arguments
 * return: NULL
 */
char *path_address(char *my_path, char *input)
{
	char *path_copy, *token_path, *file_path;

	path_copy = my_strdup(my_path);
	token_path = tokenize(path_copy, ":");
	file_path = malloc(my_strlen(input) + my_strlen(my_path) + 2);

	while (token_path != NULL)
	{
		my_strcpy(file_path, token_path);
		my_strcat(file_path, "/");
		my_strcat(file_path, input);
		my_strcat(file_path, "\0");

		if (access(file_path, X_OK) == 0)
		{
			return (file_path);
			free(file_path);
		}
		token_path = tokenize(NULL, ":");
	}
	free(file_path);
	return (NULL);
}

/*
 *get_path: function to get the path
 * @input: variable to be accepted
 *return: Null
 */

char *get_path(char *input)
{
	char *my_path, *fresh_path;

	my_path = my_getenv("PATH");

	if (my_path)
	{
		fresh_path = path_address(my_path, input);
		return (fresh_path);
	}
	return (NULL);
}

