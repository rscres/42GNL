/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/31 13:49:34 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif //BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

typedef struct s_char
{
	char			c;
	struct s_char	*next;
}	t_char;

typedef struct s_file_data
{
	int		bytesread;
	int		pos;
	char	str[BUFFER_SIZE];
}	t_data;

//List functions
void	ft_lstadd_back(t_char **lst, t_char *node);
t_char	*ft_lstnew(char content);
int		ft_lstsize(t_char *lst);

//Memory functions
void	ft_bzero(void *s, size_t n);

#endif //GET_NEXT_LINE_H