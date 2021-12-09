#include "shell.h"

void sigintHandler(__attribute__ ((unused))int sig_num)
{
	/* Reset handler to catch SIGINT next time.*/
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
