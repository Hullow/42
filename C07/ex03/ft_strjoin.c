#include <stdlib.h>
#include <stdio.h>

int	calculate_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	str_num;
	int sep_len;
	int	i;

	i = 0;
	sep_len = 0;
	str_num = 0;

	while (sep[sep_len])
		sep_len++;

	while (strs[str_num])
		str_num++;

	if (str_num > 0)
	{
		total_size = size + (str_num - 1) * sep_len;
		return (total_size);
	}
	else
		return (0);
}

//char	*fill_str()

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	total_size;
	int	i;
	int	j;
	int	r;
	int	k;

	if (strs == NULL)
		return (0);
	if (size == 0)
		result = NULL;

	i = 0;
	r = 0;
	total_size = calculate_size(size, strs, sep);
	result = (char*) malloc(total_size * sizeof(char));
	if (result == NULL)
		return (0);

	while (r < total_size)
	{
		while (strs[i])
		{
			j = 0;
			while (strs[i][j])
				{
					result[r] = strs[i][j];
					r++;
					j++;
				}
			k = 0;
			while (sep[k])
			{
				result[r] = sep[k];
				k++;
			}
			i++;
		}
	}
	return (result);
}

int	main()
{
	char *sep = " aaa! ";
	char *strs[] = {"blob", "sqrt", "horny", "ben"};
	char *result = ft_strjoin(20, strs, sep);

	printf("%s\n", result);
	return (0);

/* 		while (tab[i] >= 10 && tab[i] <= 19)
		{
			printf("%d ", tab[i]);
			i++;
		}
		printf("\n"); */
	free(result);
	return (0);
}