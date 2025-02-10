
	// pid = fork();
	// if (pid == 0)
	// {
	// 	/* we are in the child*/
	// 	handle_child_process
	// }
	// else if (pid > 0)
	// {
	// 	/* we are still in the parent process */
	// }
	// else
	// {
	// 	/* handle fork error */
	// }
	
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char *envp[])
{
	char *args[2];
	pid_t	pid;

	(void)argc;
	(void)argv;
	args[0] = "/bin/ls";
	args[1] = NULL;

	printf("before execve\n\n");
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/ls", args, envp);
		exit (0);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		write(2, "\nafter execve\n", 14);
		return (0);
	}
	else
	{
		write(2, "fork error\n", 12);
	}
	return (0);
}