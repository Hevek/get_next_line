/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:38 by restevez          #+#    #+#             */
/*   Updated: 2025/02/06 02:18:13 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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
	size_t			empty;
}	t_str_list;

char		*get_next_line(int fd);
char		*get_strings(int fd, t_str_list **buff);
void		cleanup_list(t_str_list **list);
void		append_str(t_str_list **list, char *str);
char		*ft_get_line(t_str_list *list);
char		*fill_line(t_str_list **list, size_t len);
char		*ft_strcat(char *dest, char *src, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);

#endif
