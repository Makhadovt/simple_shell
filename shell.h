#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


int exec_ld(char **args);
int exec_cd(char **args);
int exec_help(char **args);
extern char **environ;
int exec_exit(char **args);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *find_path(char **env);
int info_path(char **arg, char **env);
char *_getline_cmd(void);
void _getenv(char **env);
char **tokenizer(char *cmd_line);
void exit_cmd(char **args, char *cmd_line, int _exit);
int exec_fork(char **arg, char **av, char **env,
char *cmd_line, int n_pid, int c);


#endif /* SHELL_H */
