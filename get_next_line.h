/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:38 by restevez          #+#    #+#             */
/*   Updated: 2025/02/10 09:51:40 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef struct str_list
{
	char			*str;
	struct str_list	*next;
}	t_str_list;

char		*get_next_line(int fd);
void		fill_list(t_str_list **list, int fd);
void		append_str(t_str_list **list, char *str);
char		*ft_strchr(const char *s, int c);
char		*transfer_line(t_str_list *list);
size_t		get_line_size(t_str_list *list);
void		cleanup_list(t_str_list **list);
char		*ft_strdup(const char *s);

#endif
