/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/26 18:47:42 by rseelaen         ###   ########.fr       */
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
	char		str[1];
	t_char		*head;
	t_data		*data;
	char		*str_ret;

	data->bytesread = read(fd, str, 1);
	data->fd = fd;
	if (data->bytesread <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head = NULL;
	while (data->bytesread > 0 && data->pos <= BUFFER_SIZE)
	{
		ft_lstadd_back(&head, ft_lstnew(str[0]));
		if (str[0] == '\n')
			break ;
		str[0] = '\0';
		data->bytesread = read(fd, str, 1);
		if (data->pos == BUFFER_SIZE)
			data->pos = -1;
		data->pos++;
	}
	ft_lstadd_back(&head, ft_lstnew('\0'));
	str_ret = line_writer(&head);
	return (str_ret);
}
