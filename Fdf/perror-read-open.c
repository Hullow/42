#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	printf("argc: %d, argv[0]: %s, argv[1]: %s \n", argc, argv[0], argv[1]);

	char	output[BUFFER_SIZE + 1];

	char path[] = "/Users/fallan/42/get_next_line/examples/userinput.txt";
	int fd = open(path, O_WRONLY);
	write(fd, argv[1], BUFFER_SIZE);
	close(fd);
	fd = open(path, O_RDONLY);
	read(fd, output, BUFFER_SIZE);

	printf("output: %s\n", output);
}


// int main(void)
// {
// // example 2:
// 	// char c;
// 	// char msg[20];
// 	// char msg2[20];
// 	// char buf0[2] = {0, 0};
// 	// char buf2[2] = {0, 0};
// 	// int fd1 = open("example.txt", O_RDONLY, 0);
// 	// int fd2 = open("example.tx", O_RDONLY, 0);
// 	// // printf("fd1 = %d, fd2 = %d\n", fd1, fd2);
// 	// read(fd1, &c, 1);
// 	// read(fd2, &c, 1);
// 	// sprintf(msg, "read fd1: %d:%s", fd1, buf0);
// 	// sprintf(msg2, "read fd2: %d:%s", fd2, buf2);
// 	// perror(msg);
// 	// perror(msg2);
// 	// printf("c = %c\n", c);
// 	// exit(0);


// // example 1:
// 	int fd;
// 	char buff[1024];
// 	char path[] = "example.txt";

// 	fd = open(path, O_RDONLY);
// 	printf("fd is %d\n", fd);
// 	read(fd, buff, 5);
// 	// int ret, ret2;
// 	// ret2 = read(fd, buff, 5);
// 	// printf("read returns ret:%d %d\n", ret, ret2);
// 	printf("\n\n%s\n\n", buff);
// 	return (0);
// }