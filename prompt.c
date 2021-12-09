#include <stdio.h>
#include "shell.h"
/**
 * print_prompt - prints a prompt followed by a space
*/
void print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
