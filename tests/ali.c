#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *get_line()
{
	ssize_t bytes_read;
	size_t size = 10;
	char *comm_line;

	printf ("$ ");
/* These 2 lines are very important. */
	comm_line = (char *) malloc (size);
	bytes_read = getline (&comm_line, &size, stdin);
	if (bytes_read == -1)
	{
		return NULL;
	}
	else
	{
		return (comm_line);
	}
}

char **str_tok(char *comm_line)
{

    // La chaine de caractères à traiter.
	const char *separators = " ";

    // On cherche à récupérer, un à un, tous les mots (token) de la phrase
    // et on commence par le premier.
	char *strToken = strtok (comm_line, separators);
	return (strToken);
}

void execv(char *comm_line)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
}
pid_t *fork_child()
{
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit (1);
	}
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	if (child_pid == 0)
	{
		printf("(%u) Nooooooooo!\n", my_pid);
	}
	else
	{
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	}
	return (*child_pid);
}
void wait()
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
