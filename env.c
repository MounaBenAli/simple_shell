#include"shell.h"

 /**
  *print_env - Implement the env built-in, that prints the current environment
*/
void print_env()
{
  char **s = environ;

  for (; *s; s++)
{
	printf("%s\n", *s);
}
}
