/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:02 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	int			i;
	int			len;
	static int	pos;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		if (i == BUFFER_SIZE)
		{
			
		}
	}
	free(buffer);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		char *buffer = get_next_line(fd);
		while (buffer[i] != '\n')
		{
			write(1, &buffer[i], 1);
			i++;
		}
		write(1, "\n", 1);
		char *buffer2 = get_next_line(fd);
		i = 0;
		while (buffer2[i] != '\n')
		{
			write(1, &buffer2[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}