#include "shell.h"
/**
 * sigintHandler - removesthe ctrl + c exit signal
 *@sig_num: int unused
*/
void sigintHandler(__attribute__ ((unused))int sig_num)
{
	/* Reset handler to catch SIGINT next time.*/
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
