#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif

typedef struct s_char
{
	char			c;
	struct s_char	*next;
}	t_char;

t_char	*ft_lstnew(char content)
{
	t_char			*node;

	node = malloc(sizeof(t_char));
	if (!node)
		return (NULL);
	node->c = content;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_char *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstadd_back(t_char **lst, t_char *new)
{
	t_char	**current;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = &(*lst)->next;
		while (*current != NULL)
			current = &(*current)->next;
		*current = new;
	}
}

void	ft_lstclear(t_char **lst)
{
	t_char	*current;
	t_char	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		current->c = '\0';
		free(current);
		current = next;
	}
	*lst = NULL;
}

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
	{
		ft_lstadd_back(head, ft_lstnew(c));
	}
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
	int			i;
	static char	str[BUFFER_SIZE];
	t_char		*head;
	static int	pos;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (pos == BUFFER_SIZE || pos == 0)
	{
		printf("here\n");
		if (!read(fd, str, BUFFER_SIZE))
			return (NULL);
		pos = 0;
	}
	i = pos;
	head = NULL;
	while (i < BUFFER_SIZE)
	{
		lstcreator(&head, str[i]);
		if (str[i] == '\n')
			break ;
		else if (i == BUFFER_SIZE - 1)
		{
			memset(str, 0, BUFFER_SIZE);
			if (read(fd, str, BUFFER_SIZE))
				i = -1;
			else
				break ;
		}
		i++;
	}
	pos = i + 1;
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
		while (i < 17)
			printf("[%d]%s", i++, get_next_line(fd));	
	}
	return (0);
}
