#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
char *read_cmd(void)
{
    char buf[1024];
    char *ptr = NULL;
    char ptrlen = 0;

    while(fgets(buf, 1024, stdin))
    {
        int buflen = strlen(buf);

        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
        else
        {
            char *ptr2 = realloc(ptr, ptrlen+buflen+1);

            if(ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }

        if(!ptr)
        {
            fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
            return NULL;
        }

        strcpy(ptr+ptrlen, buf);

        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            fprintf(stderr, "$ ");
        }

        ptrlen += buflen;
    }

    return ptr;
}
char **str_tok(char *comm_line, char *sep)
{
	/**int bufsize = wordcount(line, ' ');*/
	int i = 0;
	char *tok = NULL;
	char **tokarray = NULL;

	/**tokarray = malloc(sizeof(char *) * (bufsize + 1));*/
	tokarray = malloc(1024);
	if (!tokarray)
	{
		free(tokarray);
		exit(3);
	}
	tok = strtok(comm_line, sep);
	while (tok != NULL)
	{
		tokarray[i] = tok;
		tok = strtok(NULL, sep);
		i++;
	}
	tokarray[i] = NULL;
	return (tokarray);
}
void execute(char **arrtok)
{
	int res;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("error");
		free(arrtok);
		exit(3);
	}
	if (pid == 0)
	{
		res = execve(arrtok[0], arrtok, NULL);
		if (res == -1)
		{
			perror("error");
		}
		free(arrtok);
		exit(0);
	}
	free(arrtok);
}

int main()
{
    char *cmd;
	char **tokarray = NULL;

    do
    {
        fprintf(stderr, "$ ");

        cmd = read_cmd();

        if(!cmd)
        {
            exit(EXIT_SUCCESS);
        }

        if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }

        if(strcmp(cmd, "exit\n") == 0)
        {
            free(cmd);
            break;
        }

        printf("%s\n", cmd);
	//anwer
	tokarray = str_tok(cmd, " ");
	execute (tokarray);
        free(cmd);

    } while(1);

    exit(EXIT_SUCCESS);
}
/**
//pid_t *fork_child()
//{
//	pid_t my_pid;
//	pid_t child_pid;
//
//	child_pid = fork()
//	if (child_pid == -1)
//	{
//		perror("Error:");
//		exit (1);
//	}
//	my_pid = getpid();
//	printf("My pid is %u\n", my_pid);
//	if (child_pid == 0)
//	{
//		printf("(%u) Nooooooooo!\n", my_pid);
//	}
//	else
//	{
//		printf("(%u) %u, I am your father\n", my_pid, child_pid);
//	}
//	return (*child_pid);
//}
//void wait()
//{
//	pid_t child_pid;
//	int status;
//
//	child_pid = fork();
//	if (child_pid == -1)
//	{
//		perror("Error:");
//		return (1);
//	}
//	if (child_pid == 0)
//	{
//		printf("Wait for me, wait for me\n");
//		sleep(3);
//	}
//	else
//	{
//		wait(&status);
//		printf("Oh, it's all better now\n");
//	}
//	return (0);
//}
**/
