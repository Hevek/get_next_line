/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/01/12 17:14:28 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
buff = malloc(sizeof(t_str_list));
i = -1;
buff->str = malloc(BUFFER_SIZE + 1);
if (!buff->str)
	return (NULL);
read(fd, buff->str, BUFFER_SIZE);
buff->str[BUFFER_SIZE] = '\0';
buff->next = NULL;
*/

char	*free_list(t_str_list **str)
{
	t_str_list	*next_str;

	next_str = malloc(sizeof(t_str_list));
	next_str->next = (*str)->next;
	free(str);
	while (next_str->next != NULL)
		free_list(&next_str->next);
	free(next_str);
	return (NULL);
}

void	append_str(t_str_list **list, char *str)
{
	t_str_list	*last_str;
	t_str_list	*new_str;

	if (!(*list))
	{
		(*list)->str = str;
		write(1, (*list)->str, BUFFER_SIZE);
		return ;
	}
	new_str = malloc(sizeof(t_str_list));
	if (!new_str)
	{
		free_list(list);
		return ;
	}
	last_str = (*list)->next;
	while (last_str)
		last_str = last_str->next;
	new_str->str = str;
	write(1, new_str->str, BUFFER_SIZE);
	new_str->next = NULL;
}
/*
char	*fill_line(t_str_list *list, size_t len)
{
	char	*str;

	str = malloc(len + 1);
	while (list)
	{
		ft_strcat(str, (char *) list->str);
		list = list->next;
	}
	return (str);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *) s);
}
