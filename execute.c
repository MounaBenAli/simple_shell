#include "shell.h"

/**
*execute :executes the child process referred to by pathname
*@arrtok : array of tokens from the str_tok
*/

void execute(char **arrtok)
{
	int res;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("error");
		free(arrtok);
		exit(3);
	}
	else if(pid > 0)
		wait(NULL);
	else if(pid == 0)
	{
/*		if (strcmp(arrtok[0], "env") == 0)
		{
			print_env();
			free(arrtok);
			exit(0);
		}
*/
		res = execve(arrtok[0], arrtok, NULL);
		if (res == -1)
		{
			perror("error");
		}
		free(arrtok);
		exit(0);
	}
	free(arrtok);
}
