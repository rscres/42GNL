/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:10 by rseelaen          #+#    #+#             */
/*   Updated: 2023/05/31 12:43:35 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif //BUFFER_SIZE

# ifndef FD_MAX
#  define FD_MAX 1024
# endif //FD_MAX

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
	char	*str;
}	t_data;

//List functions
void	ft_lstadd_back(t_char **lst, t_char *node);
t_char	*ft_lstnew(char content);
int		ft_lstsize(t_char *lst);

#endif //GET_NEXT_LINE_BONUS_H