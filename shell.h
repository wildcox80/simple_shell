#ifndef _SHELL_H_
#define _SHELL_H_

/* the libraries standard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Macros defined */
#define BUF_SIZE 64
#define ARG_SIZE 10
#define DELIM " \t\r\n\a"
#define MAX 1024
#define STDOUT STDOUT_FILENO
#define DELIM_PATH "=:"

extern char **environ;

/* Prototypes */
char **free_ptr(char **line);
int _putchar(char c);
void _exit_function(void);
void prompt_shell(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);
char **_strtok(char *line_msg);
char *str_concat(char *s1, char *s2);
int _equal(char *dest, char *src);
char **get_path(char **env);
char *get_line(int isatty);
void _execev(char **line, char *argv, int num, int isatty, char **envi);
int built_int(char **line, char **environ);
char *_strstr(char *haystack, char *needle);
int _equal(char *dest, char *src);
char *str_concat(char *s1, char *s2);
int chr_del(char *str, char *delimits);
int checking_path(char **env, char **argvs);
char *_getenv(const char *name);
void printenv(void);

#endif /* SHELL */

