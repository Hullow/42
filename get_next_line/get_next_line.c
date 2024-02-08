#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd;
	char buff[5];
	char path[] = "example.txt";

	fd = open(path, O_RDONLY);
	ssize_t ret = read(fd, buff, 5);
	printf("\nbuffer now contains:\n%s**********************\nand read returns %zu\n\n", buff, ret);

	close(fd);
	return (0);
}

/* int main(void)
{
	int fd;
	char buff[5];
	printf("strlen(buff) is %zu\n", strlen(buff));
	char path[] = "example.txt";

	fd = open(path, O_RDONLY);
	// printf("fd is %d\n", fd);
	ssize_t ret = read(fd, buff, 28);

	printf("\n\nbuffer contains:\n%s**********************\nand read returns %zu\n\n", buff, ret);

	close(fd);
	return (0);
}

 */

/* 
char	*get_next_line(int fd)
{
}
*/