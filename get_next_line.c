/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/25 16:45:14 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static char	*line_writer(t_char **lst)
{
	t_char	*line;
	char	*line_ret;
	int		i;

	line_ret = malloc((ft_lstsize(*lst) + 1) * sizeof(char));
	if (!line_ret)
		return (NULL);
	line = *lst;
	i = 0;
	while (line != NULL)
	{
		line_ret[i++] = line->c;
		line = line->next;
	}
	if (line_ret[i - 1] != '\0')
		line_ret[i] = '\0';
	ft_lstclear(lst);
	return (line_ret);
}

static int	line_reader(t_char **lst, int pos, int fd, char *str)
{
	while (pos <= BUFFER_SIZE)
	{
		ft_lstadd_back(lst, ft_lstnew(str[pos]));
		if (str[pos] == '\n' || str[pos] == '\0')
			break ;
		if (pos == BUFFER_SIZE - 1)
		{
			ft_memset(str, 0, BUFFER_SIZE);
			if (read(fd, str, BUFFER_SIZE) <= 0)
				break ;
			pos = -1;
		}
		pos++;
	}
	pos = pos + 1;
	return (pos);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	static int	pos;
	t_char		*head;

	if (pos == BUFFER_SIZE || pos == 0)
	{
		if (read(fd, str, BUFFER_SIZE) <= 0)
			return (NULL);
		pos = 0;
	}
	head = NULL;
	pos = line_reader(&head, pos, fd, str);
	return (line_writer(&head));
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	// int		i;
// 	// char	*line;

// 	// i = 0;
// 	if (argc < 2)
// 		printf("Nothing to read...\n");
// 	if (argc >= 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		// fd_read = open(argv[2], O_RDWR);
// 		if (fd == -1)
// 			printf("Error");
// 		else
// 		{	
// 			printf("%s", get_next_line(fd));
// 			printf("%s", get_next_line(fd));
// 			// printf("%s", get_next_line(fd));
// 			// if (!line)
// 			// 	break ;
// 		}
// 	}
// 	return (0);
// }
