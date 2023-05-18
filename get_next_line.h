/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/17 20:33:27 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif //BUFFER_SIZE

# include <stdlib.h>

char	*get_next_line(int fd);

typedef struct s_char
{
	char			c;
	struct s_char	*next;
}	t_char;

//List functions
void	ft_lstadd_back(t_char **lst, t_char *new);
t_char	*ft_lstnew(char content);
int		ft_lstsize(t_char *lst);

#endif //GET_NEXT_LINE_H