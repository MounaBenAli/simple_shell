#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct to_built
{
	char *cmd;
	int (*f)(char **args);
} builtin;
char *_strcat(char **dest, char **src);
extern char **environ;

void print_prompt(void);
char *read_cmd(void);
char **str_tok(char *comm_line, char *sep);
void execute(char **arrtok);
void print_env();
char *path(char *toka);
void sigintHandler(int sig_num);
int (*get_builtin(char **arguments))(char **);
int _cd(char **arguments);
int _help();
int _env();
int __exit();
int _history(char *cmd);
#endif
