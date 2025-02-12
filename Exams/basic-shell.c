#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "readline/readline.h"
#include "readline/history.h"

enum error {
	SPLIT_ERROR,
	EXECVE_ERROR,
	FORK_ERROR
};

int	handle_error(int error_type)
{
	if (error_type == SPLIT_ERROR)
	{
		printf("Shell: input split failed\n");
		exit(-1);
	}
	else if (error_type == EXECVE_ERROR)
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

int	count_splits(char *str)
{
	int	i;
	int	split_count;

	i = 0;
	split_count = 0;
	while (str[i])
	{
		if (is_white_space(str[i]))
		{
			i++;
			continue ;
		}
		while (str[i] && !is_white_space(str[i]))
			i++;
		split_count++;
		if (!str[i])
			break ;
		else
			i++;
	}
	return (split_count);
}

// Split for the purpose
// if separator character sep is == 0, split using is_white_space
// else, use sep to split
char	**ft_split(char *str, char sep)
{
	char	**split = NULL;
	int		i;
	int		j;
	int		char_index; // counts the length of each token
	int		word_index; // counts the number of tokens

	i = 0;
	char_index = 0;
	word_index = 0;
	if (!str || str[i] == '\0')
		return (NULL);
	split = malloc (count_splits(str) * sizeof(char *));
	if (!split)
		handle_error(SPLIT_ERROR);
	while (str[i])
	{
		if (sep == 0)
		{
			if (is_white_space(str[i]))
			{
				i++;
				continue ;
			}
		}
		else
		{
			if (str[i] == sep)
			{
				i++;
				continue ;
			}
		}
		while (str[i] && !is_white_space(str[i]))
		{
			char_index++;
			i++;
		}
		split[word_index] = malloc ((char_index + 1) * sizeof(char));
		i -= char_index;
		j = 0;
		while (j < char_index)
		{
			split[word_index][j] = str[i];
			j++;
			i++;
		}
		split[word_index][j] = '\0';
		char_index = 0;
		word_index++;
		if (!str[i])
			break ;
		i++;
	}
	split[word_index] = NULL;
	return (split);
}

char	*get_path_var(char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		while (envp[i][j])
			j++;
		if (j < 4)
			break ;
		j = 0;
		if (envp[i][j] == 'P' && envp[i][j + 1] == 'A'
				&& envp[i][j + 2] == 'T' && envp[i][j + 3] == 'H')
			return (envp[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (0);
	while(src[i] && i < size - ft_strlen(dst) - 1)
	{

		i++;
	}
}


int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*find_executable(char *executable, char **envp)
{
	char	*path_var;
	char	*possible_path;
	char	**paths = NULL;
	int		i;

	path_var =	get_path_var(envp);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		possible_path = malloc ((ft_strlen(executable) + ft_strlen(paths[i])) * sizeof(char));
		
		access
	}
	return
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
		char **args = ft_split(prompt, 0);
		char *path = malloc(strlen("/bin") + strlen(args[0]) + 1);
		if (!path)
			return (1);
		strcpy(path, "/bin/");
		strcat(path, args[0]);
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



// to test ft_split
// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (printf("not the right number of arguments (put the string between quotes)\n"));
// 	char **split = ft_split(argv[1]);
// 	int i = 0;
// 	if (!split)
// 		return (0);
// 	while (split[i])
// 	{
// 		printf("split[%d]: {%s}\n", i, split[i]);
// 		i++;
// 	}
// 	return (0);
// }