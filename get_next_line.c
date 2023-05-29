/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/29 00:48:05 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static char	*line_writer(t_char **lst)
{
	t_char	*line;
	t_char	*temp;
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
		temp = line;
		line = line->next;
		free(temp);
	}
	line_ret[i] = '\0';
	*lst = NULL;
	return (line_ret);
}

//Need to refactor this function
char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	static int	pos;
	t_char		*head;
	static int	bytesread;

	if (pos >= bytesread || pos == 0)
	{
		pos = 0;
		bytesread = read(fd, str, BUFFER_SIZE);
	}
	if (bytesread <= 0 || str[pos] == '\0')
		return (NULL);
	head = NULL;
	while (bytesread > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(str[pos]));
		if (str[pos] == '\n' || str[pos] == '\0')
			break ;
		if (pos == bytesread - 1 || bytesread == 1)
		{
			pos = -1;
			memset(str, 0, BUFFER_SIZE);
			if (read(fd, str, BUFFER_SIZE) <= 0)
				break ;
		}
		pos++;
	}
	pos++;
	return (line_writer(&head));
}
