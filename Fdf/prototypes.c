typedef struct	s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_list	*point_list;
}				t_env;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	*ft_fill_list_element(char **split_string, int i, int j, int *line_data)
{
	int	*point;

	point = (int *)malloc (5 * sizeof(int));
	point[0] = j;
	point[1] = i;
	point[2] = ft_atoi(split_string[j]);
	point[3] = line_data[0];
	point[4] = line_data[1];
	return (point);
}

// accessing the first point of the list:
env->point_list->content[0]