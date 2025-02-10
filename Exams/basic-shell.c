#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

int	ft_execute(char	*prompt, char ***envp)
{
	int		exit_status;
	pid_t	pid;

	exit_status = 0;
	if (!prompt || strlen(prompt) == 0)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		char *args[2];
		args[0] = prompt;
		args[1] = NULL;
		const char *path = strcat("/bin/", args[0]);
		printf("path: %s\n", path);
		if (execve("/bin/ls/", args, *envp) == -1)
		{
			printf("execve error\n");
			exit(-1);
		}
		printf("execve'd {%s}\n", path);
		exit(0);
	}
	else if (pid == -1)
	{
		printf("execution error\n");
		return (-1);
	}
	else
	{
		waitpid(pid, NULL, 0);
		printf("parent\n");
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*prompt;
	int		exit_status;

	(void)argc;
	(void)argv;
	exit_status = 0;
	while (prompt != NULL)
	{
		prompt = readline("Shell>");
		add_history(prompt);
		exit_status = ft_execute(prompt, &envp);
		// printf("exit status == %d\n", exit_status);
	}
}