/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:52:40 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/27 19:54:34 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	// int		i;

	// i = 0;
	line = NULL;
	if (argc < 2)
		printf("Nothing to read...\n");
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		// fd_read = open(argv[2], O_RDWR);
		if (fd == -1)
			printf("Error");
		else
		{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);

		line = get_next_line(fd2);
		printf("%s", line);
		free(line);

		line = get_next_line(fd2);
		printf("%s", line);
		free(line);

		line = get_next_line(fd);
		printf("%s", line);
		free(line);

		line = get_next_line(fd2);
		printf("%s", line);
		free(line);

		line = get_next_line(fd3);
		printf("%s", line);
		free(line);

		line = get_next_line(fd);
		printf("%s", line);
		free(line);

		line = get_next_line(fd2);
		printf("%s", line);
		free(line);

		line = get_next_line(fd3);
		printf("%s", line);
		free(line);

		line = get_next_line(fd);
		printf("%s", line);
		free(line);

		line = get_next_line(fd2);
		printf("%s", line);
		free(line);

		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
			// if (!line)
			// 	break ;
		}
	}
	return (0);
}

// #include <stdio.h>	// FILE, fopen()
// #include <stdio.h> // printf()
// #include <stdlib.h> // free()

// char	*g_file_name = "./only_skin";
// FILE	*g_fp;

// char	*get_next_line(int fd);

// int main()
// /**
// *	- Function main() opens a file in a file descriptor (fd / _fileno).
// *	- This file contains text meant to be read one line at a time by means
// *	of function get_next_line().
// *	- Each call must return a string of chars ended tied up with a '\n', so long
// *	as there is one. Empty lines are returned all the same (one single '\n' per call).
// *	- main() proceeds to print the resulting line read by get_next_line(),
// *	looping throughout the file.
// *	- Once EOF is reached, get_next_line() returns NULL and stops execution;
// *	main() closes the file, and the program comes to a halt.
// **/
// {
// 	char	*linha;
// 	int		i = 0;

// 	g_fp = fopen(g_file_name, "r");
	
// 	while((linha = get_next_line(g_fp->_fileno)) != NULL)
// 	{
// 		printf("Line %i >>> %s", i++, linha);
// 		free(linha);
// 	}
	
// 	fclose(g_fp);
// 	return (0);
// }
