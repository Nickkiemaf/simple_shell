#include "shell.h"
/*
 * my_strlen: function to calculate the lenght of a string
 * @s: string
 * return: length of string on success
 */

int my_strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

/*
 * my_strcpy: copies the content of a string
 * @dest: pointer to copied string
 * @src: pointer to original string
 * return: copied string on success
 */
char *my_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}

	for (; x < l; x++)
	{
		dest[x] = src[x];
	}

	dest[l] = '\0';

	return (dest);
}

/*
 * my_strdup: function to duplicate a string
 * @str: pointer to initial string
 * @duplicate: pointer to duplicated string
 * retrun: duplicated string
 */
char *my_strdup(char *str)
{
	size_t len;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	len = my_strlen(str);
	duplicate = (char *)malloc(len + 1);

	if (duplicate != NULL)
	{
		my_strcpy(duplicate, str);
	}

	return (duplicate);
}

/*
 * my_strcat: function to concatenate strings
 * @str1: first string
 * @str2: second string
 * return: strings
 */
char *my_strcat(char *str1, char *str2)
{
	int k, l;

	k = 0;
	l = 0;
	while (str1[k] != '\0')
	{
		k++;
	}
	str1[k] = ' ';
	while (str2[l] != '\0')
	{
		str1[k] = str2[l];
		k++;
		l++;
	}
	str1[k] = '\0';

	return (str1);
}

