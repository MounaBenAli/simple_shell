#include "shell.h"

/**
 * path - Searches the PATH for the matching command line
 * @toka: command (ex: ls)
 * Return: command path (ex: /bin/ls)
*/

char *path(char *toka)
{
	int x = 0, y = 0, z = 0, w = 0;
	char *tok[100], *str, *path, ch[100], *envi;
	struct stat st;

	while (environ[x] != NULL)
	{envi = strdup(environ[x]);
		str = strtok(envi, "=");
		if (strcmp(envi, "PATH") == 0)
		{str = strtok(NULL, "=");
			break; }
		x++; }
	path = str;
	str = strtok(path, ":");
	while (str)
	{tok[y] = str;
		str = strtok(NULL, ":");
		y++; }
		tok[y] = NULL;
	while (tok[z])
		z++;
	while (tok[w])
	{
		strcpy(ch, tok[w]);
		strcat(ch, "/");
		strcat(ch, toka);
		if (stat(ch, &st) == 0)
		{toka = ch;
			return (toka); }
		w++; }
	return (NULL);
}
