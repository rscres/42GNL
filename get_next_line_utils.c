/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:21:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/18 15:10:50 by rseelaen         ###   ########.fr       */
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
		free(current->c);
		free(current);
		current = next;
	}
	*lst = NULL;
}
