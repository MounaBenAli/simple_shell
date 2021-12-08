#include <stdio.h>
#include "shell.h"

void print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
	  
}
