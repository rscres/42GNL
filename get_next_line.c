/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/22 21:01:42 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

t_char	*lstcreator(t_char **head, char c)
{
	t_char		*line;

	if (!head)
	{
		line = ft_lstnew(c);
		if (!line)
			return (NULL);
		*head = line;
	}
	else
		ft_lstadd_back(head, ft_lstnew(c));
}

char	*linewriter(t_char **head)
{
	t_char	*line;
	char	*line_ret;
	int		len;

	len = ft_lstsize(*head);
	line_ret = malloc((len) * sizeof(char));
	line = *head;
	if (!line_ret)
		return (NULL);
	len = 0;
	while (line != NULL)
	{
		line_ret[len] = line->c;
		len++;
		line = line->next;
	}
	line_ret[len] = '\0';
	ft_lstclear(head);
	return (line_ret);
}



char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	static int	pos;
	t_char		*head;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (pos == BUFFER_SIZE || pos == 0)
	{
		if (!read(fd, str, BUFFER_SIZE))
			return (NULL);
		pos = 0;
	}
	head = NULL;
	while (pos < BUFFER_SIZE)
	{
		lstcreator(&head, str[pos]);
		if (str[pos] == '\n')
			break ;
		else if (pos == BUFFER_SIZE - 1)
		{
			ft_memset(str, 0, BUFFER_SIZE);
			if (read(fd, str, BUFFER_SIZE))
				pos = -1;
			else
				break ;
		}
		pos++;
	}
	pos = pos + 1;
	return (linewriter(&head));
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (i++ < 17)
			printf("%s", get_next_line(fd));
	}
	return (0);
}
