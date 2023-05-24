/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:21:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/23 14:57:31 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_lstadd_back(t_char **lst, t_char *node)
{
	t_char	**current;

	if (!node)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		current = &(*lst)->next;
		while (*current != NULL)
			current = &(*current)->next;
		*current = node;
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

void	*ft_memset(void *ptr, int c, size_t num)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	buffer = ptr;
	while (i < num)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	buffer[i] = '\0';
	return (ptr);
}
