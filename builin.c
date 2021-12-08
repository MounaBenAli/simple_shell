#include "shell.h"

int (*get_builtin(char **arguments))(char **)
{
	builtin command[] = {
		{"cd", _cd},
		{"help", _help},
		{NULL, NULL}};
	int i = 0;

	while (command[i].cmd)
	{
		if (strcmp(arguments[0], command[i].cmd) == 0)
			return (*(command[i].f));
		i++;
	}

	return (NULL);
}
int _help()
{
	puts("\n***WELCOME TO MY SHELL HELP**"
		"\nCopyright @ Suprotik Dey"
		"\n-Use the shell at your own risk..."
		"\nList of Commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>exit"
	"\n>all other general commands available in UNIX shell"
        "\n>pipe handling"
        "\n>improper space handling");

	return (0);
}

void sigintHandler(__attribute__ ((unused))int sig_num)
{
	/* Reset handler to catch SIGINT next time.*/
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
int _cd(char **arguments)
{
	if (arguments[1] == NULL)
		printf("Expected argument to \"cd\"\n");
	else
	{
		if (chdir(arguments[1]) != 0)
			perror("Expected argument to cd\n");
	}

	return (0);
}
