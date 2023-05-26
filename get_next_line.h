/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/26 11:57:04 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

typedef struct s_char
{
	char			c;
	struct s_char	*next;
}	t_char;

typedef struct s_file_data
{
	int	bytesread;
	int	pos;
	int	fd;
}	t_file_data;


//List functions
void	ft_lstadd_back(t_char **lst, t_char *node);
void	ft_lstclear(t_char **lst);
t_char	*ft_lstnew(char content);
int		ft_lstsize(t_char *lst);

//Mem function
void	*ft_memset(void *ptr, int c, size_t num);

#endif //GET_NEXT_LINE_H