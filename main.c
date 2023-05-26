/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:52:40 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/26 17:53:31 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	// int		i;
	// char	*line;

	// i = 0;
	if (argc < 2)
		printf("Nothing to read...\n");
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		// fd_read = open(argv[2], O_RDWR);
		if (fd == -1)
			printf("Error");
		else
		{
			printf("%s", get_next_line(fd));
			printf("%s", get_next_line(fd));
			printf("%s", get_next_line(fd));
			// if (!line)
			// 	break ;
		}
	}
	return (0);
}
