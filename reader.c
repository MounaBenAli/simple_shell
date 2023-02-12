#include"shell.h"
/**
 * read_cmd - reads input from stdin in 1024-byte chunks
 *
 * Description: This function reads input from stdin in 1024-byte chunks
 * and returns a pointer to the user input.
 * If the user input is "exit" or "env",the function
 * removes the newline character at the end of the string.
 *
 * Return: On success, a pointer to the user input. On failure, NULL.
 */


char *read_cmd(void)
{
	char *cmd = NULL;
	size_t buffsize;

	getline(&cmd, &buffsize, stdin);
	if (strcmp(cmd, "exit\n") != 0 && strcmp(cmd, "env\n") != 0)
		cmd[strlen(cmd) - 1] = '\0';

	return (cmd);
}
