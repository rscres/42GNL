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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = strlen(s1);
	len2 = strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i <= len1)
		*(str + i) = *(s1 + i);
	i -= 1;
	while (i++ < (len2 + len1))
		*(str + i - 1) = *(s2 + i - len1 - 1);
	*(str + i - 1) = '\0';
	return (str);
}

void	get_next_line(int fd)
{
	int			i;
	char		str[BUFFER_SIZE];
	static int	pos;

	if (BUFFER_SIZE <= 0)
		return ;
	if (pos == BUFFER_SIZE || pos == 0)
	{
		read(fd, str, BUFFER_SIZE);
		pos = 0;
	}
	i = pos;
	while (i <= BUFFER_SIZE)
	{
		write (1, &str[i], 1);
		if (str[i] == '\n')
			break ;
		else if (i == BUFFER_SIZE)
		{
			memset(str, 0, strlen(str));
			read(fd, str, BUFFER_SIZE);
			i = -1;
		}
		else if (str[i] == '\0')
		{
			break ;
		}
		i++;

	}
	pos = i + 1;
	// printf("%d\n", pos);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
	}
	return (0);
}
