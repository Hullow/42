#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

enum error {
	EXECVE_ERROR,
	FORK_ERROR
};

int	handle_error(int error_type)
{
	if (error_type == EXECVE_ERROR)
	{
		perror("Shell:");
		exit(-1);
	}
	else if (error_type == FORK_ERROR)
	{
		printf("fork error\n");
		return (-1);
	}
	return (0);
}

int	ft_execute(char	*prompt, char **envp)
{
	int		exit_status;
	pid_t	pid;

	exit_status = 0;
	if (!prompt || strlen(prompt) == 0)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		sleep(10);
		char *args[2];
		args[0] = prompt;
		args[1] = NULL;
		const char *path = strcat("bin/", args[0]);
		printf("path: %s\n", path);
		if (execve("/bin/ls/", args, envp) == -1)
			handle_error(EXECVE_ERROR);
		printf("execve'd {%s}\n", path);
		exit(0);
	}
	else if (pid == -1)
		return (handle_error(FORK_ERROR));
	else
	{
		waitpid(pid, NULL, 0);
		printf("back in parent\n");
	}
	return (exit_status);
}

int main(int argc, char **argv, char **envp)
{
	char	*prompt;
	int		exit_status;

	(void)argc;
	(void)argv;
	exit_status = 0;
	prompt = readline("Shell>");
	while (prompt != NULL)
	{
		add_history(prompt);
		exit_status = ft_execute(prompt, envp);
		printf("exit status == %d\n", exit_status);
		prompt = readline("Shell>");
	}
}