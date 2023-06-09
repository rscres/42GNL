/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:15 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/27 19:33:21 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static int	pos;
	t_char		*head;
	int			bytesread;
	// char		*str_ret;

	bytesread = read(fd, str, 1);
	if (bytesread <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head = NULL;
	while (bytesread > 0 && pos <= BUFFER_SIZE)
	{
		ft_lstadd_back(&head, ft_lstnew(str[0]));
		if (str[0] == '\n')
			break ;
		str[0] = '\0';
		bytesread = read(fd, str, 1);
		if (pos == BUFFER_SIZE)
			pos = -1;
		pos++;
	}
	ft_lstadd_back(&head, ft_lstnew('\0'));
	// str_ret = line_writer(&head);
	return (line_writer(&head));
}
