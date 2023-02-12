#include "shell.h"

/**
 * path - Searches the PATH for the matching command line
 * @toka: command (ex: ls)
 * Return: command path (ex: /bin/ls)
*/

char *path(char *toka)
{
	char *path = getenv("PATH");
	const char sep = ':';
	char *tok[100], ch[100];
	struct stat st;


	if (!path)
		return (NULL);

	char *str = strtok(path, &sep);
	int y = 0;

	while (str)
	{
		tok[y++] = str;
		str = strtok(NULL, &sep);
	}
	tok[y] = NULL;

	for (int w = 0; tok[w]; w++)
	{
		snprintf(ch, sizeof(ch), "%s/%s", tok[w], toka);
		if (stat(ch, &st) == 0)
		{
			return (strdup(ch));
		}
	}
	return (NULL);
}
