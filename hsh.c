#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char *buffer = NULL;
	char *args[] = {buffer, NULL};

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	getline(&buffer,&bufsize,stdin);
		args[0] = buffer;
                if (execve(args[0], args, NULL) == -1)
                {
                        perror("Error:aaaaaaaaaaaaaaaaaaaa");
                }
		printf("#cisfun$ ");
		getline(&buffer,&bufsize,stdin);
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error:aaaaaaaaaaaaaaaaaaaa");
		}

	return(0);
}
