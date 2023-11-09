#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>

extern char **environ;
char *get_path(char *input);
char *path_address(char *my_path, char *input);
void excve_command(char **token, char *prg);
void mathail_token(char *address, char **token);
void mathail_print(char *jb_strings);
int mathail_exit(const char *input);
int mikail_env(int i, char *address, char *envp[]);
char* tokenize(char* str, const char* delim);
char* strchar(const char* str, int s);
int my_strlen(char *s);
char *my_strcpy(char *dest, char *src);
int err_msg(char *prg, char **address, int i);
int print_int(int numb);
char *my_getenv(char *address);
char *my_strdup(char *str);
int _strncmp(const char *destination, char *source, int num);
char *my_strcat(char *str1, char *str2);
/*ssize_t my_getline(char **line, size_t *n, char file_descriptor);*/

#endif
