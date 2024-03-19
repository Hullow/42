char	*get_next_line(int fd)
{
	char			*buf;
	char			*temp;
	static char		next_lines[BUFFER_SIZE];
	static int		read_ret = BUFFER_SIZE;
	struct Result	res;

	if (fd == -1)
		return (NULL);
	res.line = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (!ft_strlen(next_lines))
		read_ret = ft_read(fd, buf, read_ret);
	else
		ft_strlcpy(buf, next_lines, BUFFER_SIZE + 1);
	res = ft_fill_line(buf, res.line, read_ret, fd);
	read_ret = res.read_ret;
	temp = res.line;
	if (ft_end_of_line(res.buf))
	{
		temp = NULL;
		res.line = ft_add_string(res.buf, ft_end_of_line(res.buf), res.line);
	}
	ft_next_lines(next_lines, buf);
	free(buf);
	if (temp)
		free(temp);
	if (read_ret == -1)
		return (NULL);
	return (res.line);
}