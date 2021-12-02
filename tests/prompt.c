#include <stdio.h>
#include <stdlib.h>
char *get_line()
{
	ssize_t bytes_read;
	size_t size = 10;
	char *string;

	printf ("$ ");
/* These 2 lines are very important. */
	string = (char *) malloc (size);
	bytes_read = getline (&string, &size, stdin);
	if (bytes_read == -1)
	{
		return NULL;
	}
	else
	{
		return (string);
	}
}
