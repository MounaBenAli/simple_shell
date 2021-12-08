#include"shell.h"
/**
 * read_cmd : reads the input from stdin in 1024-byte chunks and stores input in a buffer
 * Return : on success pointer to the user input 
 */


char *read_cmd(void)
{
	char *cmd = NULL;
	size_t buffsize;

	getline(&cmd, &buffsize, stdin);
	if (strcmp(cmd, "exit\n") != 0)
		cmd[strlen(cmd) - 1] = '\0';
	return (cmd);
}
