#include "shell.h"
/*
* tokenize: function to tokenize a string
* @str: string to tokenize
* @delim: delimiter to use in tokenizing
* return: a pointer to the next token or NULL when no token is left
*/
char* tokenize(char* str, const char* delim)
{
    static char* string = NULL;
    char* tokenStart;
    
    if (str != NULL)
    {
        string = str;
    }

    if (string == NULL)
    {
        return NULL;
    }


/* loop to find the beginning of string */
while (*string != '\0' && strchar(delim, *string) != NULL)
{
    string++;
}

if (*string == '\0')
{
    string = NULL;
    return NULL;
}
tokenStart = string;

/* loop to find the end of the string */
while (*string != '\0' && strchar(delim, *string) == NULL)
{
    string++;
}

if (*string != '\0')
{
    *string = '\0';
    string++;
}
    return tokenStart;
}


/*
* my_strchar : function to search for a character in a string
*
* return: a pointer to the character or NULL when the character isn't found
* @str: string to search
* @s : character to search
*/
char* strchar(const char* str, int s)
{
    while (*str != '\0')
    {
        if (*str == s)
        {
            return (char*)str;
        }
            str++;
    }
    return NULL;
}
