#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child1_pid, child2_pid, child3_pid, child4_pid, child5_pid;
	int status;
	char *argv[] = {"ls", "-l", "/tmp/", NULL};

	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	child5_pid = fork();
	if (child5_pid != 0)
	{
		printf("5(%u) %u, I am your father\n", my_pid, child5_pid);
		execl("ls", "-l", "/tmp/", (char *) 0);
		sleep(5);
		wait(&status);
		child4_pid = fork();
		if (child4_pid != 0)
		{
			printf("4(%u) %u, I am your father\n", my_pid, child4_pid);
			execl("ls", "-l", "/tmp/", (char *) 0);
			sleep(3);
			wait(&status);
			child3_pid = fork();
			if (child3_pid != 0)
			{
				printf("3(%u) %u, I am your father\n", my_pid, child3_pid);
				execl("ls", "-l", "/tmp/", (char *) 0);
				sleep(3);
				wait(&status);
				child2_pid = fork();
				if (child2_pid != 0)
				{
					printf("2(%u) %u, I am your father\n", my_pid, child2_pid);
					execl("ls", "-l", "/tmp/", (char *) 0);
					sleep(3);
					wait(&status);
					child1_pid = fork();
					if (child1_pid != 0)
					{
						printf("1(%u) %u, I am your father\n", my_pid, child1_pid);
						execve(argv[0], argv, NULL);
						sleep(3);
					}
				}
			}
		}
	}
	return (0);
}
