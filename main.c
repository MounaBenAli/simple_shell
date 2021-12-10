#include "shell.h"
/**
 * main - this is our custom UNIX command line interpreter
 *Return: 0 on success
 */
int main(void)
{
	char *cmd;
	char **tokarray = NULL;
	struct stat st;

	signal(SIGINT, sigintHandler);
	do	{
		print_prompt();
		cmd = read_cmd();
		if (!cmd)
			exit(EXIT_SUCCESS);
		if (strcmp(cmd, "exit\n") == 0 || feof(stdin))
		{	free(cmd);
			break;	}
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{	free(cmd);
			continue;	}
		if (strcmp(cmd, "env\n") == 0)
		{	print_env();
			free(cmd);
			continue;	}
		tokarray = str_tok(cmd, " ");
		if (stat(tokarray[0], &st) != 0)
			tokarray[0] = path(tokarray[0]);
		execute(tokarray);
		free(cmd);
	}	while (1);
	exit(EXIT_SUCCESS);
}
