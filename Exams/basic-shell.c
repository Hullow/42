#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include <readline/readline.h>
#include <readline/history.h>

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

bool	is_white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		char_index; // counts the length of each token
	int		word_index; // counts the number of tokens

	i = 0;
	j = 0;
	char_index = 0;
	word_index = 0;
	while (str[i])
	{
		if (!is_white_space(str[i]))
			char_index++;
		else
		{
			if (char_index)
				split[word_index] = malloc ((char_index + 1) * sizeof(char));
			i -= char_index;
			j = 0;
			while (j < char_index)
			{
				split[word_index][j] = str[i];
				i++;
				j++;
			}
			char_index = 0;
			word_index++;
		}
		i++;
	}
	return (split);
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
		char *args[2];
		args[0] = prompt;
		args[1] = NULL;
		char *path = malloc(strlen("/bin") + strlen(prompt) + 1);
		if (!path)
			return (1);
		strcpy(path, "/bin/");
		strcat(path, prompt);
		printf("path is %s\n", path);
		if (execve(path, args, envp) == -1)
			handle_error(EXECVE_ERROR);
		exit(1);
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