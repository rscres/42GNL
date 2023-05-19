#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif

void	readfile(int fd, int pos, char *buffer)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = read(fd, buffer, 1);
		pos++;
		if (buffer[i] == '\n')
			break ;
		i++;
	}
}

void	get_next_line(int fd)
{
	int i;
	char	*str;
	int end = 0;
	static int pos;

	if (BUFFER_SIZE <= 0)
		return ;
	i = 0;
	str = (char *)malloc(BUFFER_SIZE * sizeof(char));
	readfile(fd, pos, str);
	while (str[i] != '\n' && str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	// while (i <= BUFFER_SIZE)
	// {
	// 	write(1, &str[i], 1);
	// 	pos++;
	// 	if (str[i] == '\n')
	// 		break ;
	// 	if (i == BUFFER_SIZE)
	// 	{
	// 		i = 0;
	// 		read(fd, str, BUFFER_SIZE);
	// 	}
	// 	else
	// 		i++;

	// }
	printf("%d\n", pos);
}

int main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}