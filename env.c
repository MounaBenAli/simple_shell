#include"shell.h"

/**
 * print_env - Implement the env built-in, that prints the current environment
 * Return: NULL
*/
void print_env(void)
{
	char **s = environ;

	for (; *s; s++)
	{
		printf("%s\n", *s);
	}
}
