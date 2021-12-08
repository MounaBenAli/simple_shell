#include "shell.h"
/**
 * Main - this is our custom UNIX command line interpreter
 *
 */


int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char **argv, __attribute__ ((unused))char **env)
{

	char *cmd;
	char **tokarray = NULL;
	struct stat st;

do
{
	print_prompt();
	cmd = read_cmd();
	if(!cmd)
	{
	exit(EXIT_SUCCESS);
	}
	if(strcmp(cmd, "exit\n") == 0)
	{
		free(cmd);
		break;
	}
	if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
	{
	free(cmd);
	continue;
	}
	tokarray = str_tok(cmd," ");
	if(stat(tokarray[0], &st) != 0)
	{
	tokarray[0] = path(tokarray[0]);
	}
	execute(tokarray);
	if (strcmp(cmd, "env\n") == 0)
		print_env();
	free(cmd);

}while(1);
	exit(EXIT_SUCCESS);
}
