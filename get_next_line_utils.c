/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/01/14 04:22:35 by restevez         ###   ########.fr       */
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

	if ((*list)->empty)
	{
		(*list)->str = ft_strdup(str);
		(*list)->empty = 0;
		(*list)->next = NULL;
		return ;
	}
	new_str = malloc(sizeof(t_str_list));
	if (!new_str)
	{
		free_list(list);
		return ;
	}
	last_str = (*list);
	while (last_str->next)
		last_str = last_str->next;
	new_str->str = ft_strdup(str);
	new_str->empty = 0;
	new_str->next = NULL;
	last_str->next = new_str;
}

char	*fill_line(t_str_list *list, size_t len)
{
	char	*str;

	str = malloc(len + 1);
	while (list)
	{
		ft_strcat(str, list->str, len);
		list = list->next;
	}
	return (str);
}
