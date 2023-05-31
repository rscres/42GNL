//888888888888888888888888*****************************88888888888888888888//

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

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

// static char	*line_reader(t_data *data, t_char *head, int fd)
// {
// 	while (data->bytesread > 0)
// 	{
// 		ft_lstadd_back(&head, ft_lstnew(data->str[data->pos]));
// 		if (data->str[data->pos] == '\n' || data->str[data->pos] == '\0')
// 			break ;
// 		if (data->pos == data->bytesread - 1 || data->bytesread == 1)
// 		{
// 			data->pos = -1;
// 			memset(data->str, 0, BUFFER_SIZE);
// 			if (read(fd, data->str, BUFFER_SIZE) <= 0)
// 				break ;
// 		}
// 		data->pos++;
// 	}
// 	data->pos++;
// 	return (line_writer(&head));
// }

// char	*get_next_line(int fd)
// {
// 	t_char			*head;
// 	static t_data	data[FD_MAX];

// 	if (data[fd].pos >= data[fd].bytesread || data[fd].pos == 0)
// 	{
// 		data[fd].pos = 0;
// 		data[fd].str = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 		data[fd].bytesread = read(fd, data[fd].str, BUFFER_SIZE);
// 	}
// 	if (data[fd].bytesread <= 0 || data[fd].str[data[fd].pos] == '\0')
// 		return (NULL);
// 	head = NULL;
// 	free(data[fd].str);
// 	return (line_reader(&data[fd], head, fd));
// }

static char	*line_reader(t_data *data, t_char *head, int fd)
{
	while (data->bytesread > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(data->str[data->pos]));
		if (data->str[data->pos] == '\n' || data->str[data->pos] == '\0')
			break ;
		if (data->pos == data->bytesread - 1 || data->bytesread == 1)
		{
			data->pos = -1;
			memset(data->str, 0, BUFFER_SIZE);
			if (read(fd, data->str, BUFFER_SIZE) <= 0)
			{
				free(data->str);
				break ;
			}		
		}
		data->pos++;
	}
	data->pos++;
	return (line_writer(&head));
}

char	*get_next_line(int fd)
{
	t_char			*head;
	static t_data	data[FD_MAX];

	if (data[fd].pos >= data[fd].bytesread || data[fd].pos == 0)
	{
		data[fd].pos = 0;
		data[fd].str = malloc((BUFFER_SIZE) * sizeof(char));
		if (!data[fd].str)
			return (NULL);
		data[fd].bytesread = read(fd, data[fd].str, BUFFER_SIZE);
	}
	if (data[fd].bytesread <= 0 || data[fd].str[data[fd].pos] == '\0')
	{
		free(data[fd].str);
		return (NULL);
	}
	head = NULL;
	return (line_reader(&data[fd], head, fd));
}
