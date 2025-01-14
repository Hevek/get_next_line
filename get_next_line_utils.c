/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/01/14 05:19:49 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanup_list(t_str_list **list)
{
	return ((*list)->str);
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
		cleanup_list(list);
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
	/* while (next_str->next != NULL) // Cleanup list using len
	{
		str = next_str->str;
		while (*str && *str != '\n')
			str++;
		if (*str == '\n')
		{
			str = ft_strdup(str);
			free(next_str->str);
			next_str->str = str;
			break ;
		}
	} */
	return (str);
}
