#ifndef _SHELL_H_
#define _SHELL_H_
/* the above is written to avoid double inclusion */

/* the libraries standard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Macros defined */
#define BUF_SIZE 64
#define ARG_SIZE 10
#define DELIM " \t\r\n\a"
#define MAX 1024
extern char **environ;

/* Prototypes */
int _putchar(char c);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strfind(char c, char *s);
char *num_to_string(int num);
char **split_lines(char *line, char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *get_line(void);
void printprompt(char *prompt);
void print_error(char *prog, int loop_count, char *line);
int builtins(char *line);
int execute(char **tokens, struct stat *st);
pid_t jw_sh(char *prog, char *line, char **tokens, int loop_count);
void printenv(void);
char *getpath(char *name);
char *_getenv(const char *name);
int get_char(void);

#endif /* SHELL */

