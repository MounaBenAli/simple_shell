#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char *buffer = NULL;
	size_t buffsize = 10;
	int buff_bytes_r;
	char *args[] = {buffer, NULL};

	buffer = (char *)malloc(buffsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("#cisfun$ ");
	buff_bytes_r = getline(&buffer,&buffsize,stdin);
	args[0] = buffer;
	if (buff_bytes_r == -1)
		puts("ERROR");
	else
	{
		if (execve(buffer, buff_bytes_r, NULL) == -1)
		{
			perror("Error:aaaaaaaaaaaaaaaaaaaa");
		}
	}

	return(0);
}
