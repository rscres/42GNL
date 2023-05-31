/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/31 13:41:05 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_writer(t_char **lst)
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

char	*line_reader(t_data *data, t_char *head, int fd)
{
	while (data->bytesread > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(data->str[data->pos]));
		if (data->str[data->pos] == '\n' || data->str[data->pos] == '\0')
			break ;
		if (data->pos == data->bytesread - 1 || data->bytesread == 1)
		{
			data->pos = -1;
			free(data->str);
			data->str = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (!data->str)
				return (line_writer(&head));
			data->bytesread = read(fd, data->str, BUFFER_SIZE);
			if (data->bytesread == -1)
				return (line_writer(&head));
		}
		data->pos++;
	}
	data->pos++;
	return (line_writer(&head));
}

char	*get_next_line(int fd)
{
	static t_data	data[FD_MAX];
	t_char			*head;
	t_data			*current;

	current = &data[fd];
	if (current->pos >= current->bytesread || current->pos == 0)
	{
		current->pos = 0;
		if (current->str)
			free(current->str);
		current->str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!current->str)
			return (NULL);
		current->bytesread = read(fd, current->str, BUFFER_SIZE);
	}
	if (current->bytesread <= 0 || current->str[current->pos] == '\0')
		return (NULL);
	head = NULL;
	return (line_reader(current, head, fd));
}
