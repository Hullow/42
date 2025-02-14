#include <stdio.h>
#include <unistd.h>

/* int pipe(int pipefd[2]);

	pipefd[0]: read end of the pipe
	pipefd[1]: write end of the pipe

	Data written to the write end of the pipe is buffered by the kernel
	until it is read from the read end of the pipe.

	Returns: 0 on success, -1 on error (with errno), and pipefd left unchanged
*/

int	piping(char **argv)
{
	argv[1] =

	return (0);
}


int main(int argc, char **argv, char **envp)
{
	if (argc != 4)
		return (printf("need 3 arguments\n"));
	
	return (0);
}

