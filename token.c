#include"shell.h"
#include<string.h>


/**
 * str_tok - splits a string into tokens
 * @comm_line : string from stdin
 * @sep: delimiter of tokens in the parsed string
 * Return: an array of tokens for each word of the string.
 */
char **str_tok(char *comm_line, char *sep)
{
	/**int bufsize = wordcount(line, ' ');*/
	int i = 0;
	char *tok = NULL;
	char **tokarray = NULL;

	tokarray = malloc(1024);
	if (!tokarray)
	{
		free(tokarray);
		return (NULL);
	}
	tok = strtok(comm_line, sep);
	while (tok != NULL)
	{
		tokarray[i] = tok;
		tok = strtok(NULL, sep);
		i++;
	}
	tokarray[i] = NULL;
	free(tok);
	return (tokarray);
}

