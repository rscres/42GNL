/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/27 20:47:53 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	char			str[1];
	static t_data	data[FD_MAX];
	t_char			*head;

	data[fd].bytesread = read(fd, str, 1);
	if (data[fd].bytesread <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head = NULL;
	while (data[fd].bytesread > 0 && data[fd].pos <= BUFFER_SIZE)
	{
		ft_lstadd_back(&head, ft_lstnew(str[0]));
		if (str[0] == '\n')
			break ;
		str[0] = '\0';
		data[fd].bytesread = read(fd, str, 1);
		if (data[fd].pos == BUFFER_SIZE)
			data[fd].pos = -1;
		data[fd].pos++;
	}
	ft_lstadd_back(&head, ft_lstnew('\0'));
	return (line_writer(&head));
}