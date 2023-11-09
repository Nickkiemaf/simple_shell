#include "shell.h"

/**
 * _getenv - Collects any environment variable
 * @address: Input
 * Return: Environ if successful else NULL
 */
 char *my_getenv(char *address)
 {
	int i = 0;
	while (environ[i])
	{
		if (_strncmp(address, environ[i], my_strlen(address)) == 0 && environ[i][my_strlen(address)] == '=')
		{
			return(environ[i] + my_strlen(address));
		}
		i++;
	}

	return(NULL);

 }

/**
 * _strncmp - Compares input with a specified length of string.
 *            Used in exit() & _getenv()
 * @destination: Input
 * @source: Specified string
 * @num: Length or size of string
 * Return: Always 0 if successful
 */
int _strncmp(const char *destination, char *source, int num)
{
	while (num && *destination == *source)
	{
		num--;
		destination++;
		source++;
	}
	if (num)
		return (*destination - *source);

	return (0);
}
