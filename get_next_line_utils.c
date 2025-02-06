/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/02/06 03:26:01 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Run through the list
while (node exists)
{
	if (node->next == NULL)
	{
		if (node->str contains '\n')
		{
			this one we do not cleanup, return;
		}
		else
			free();
	}
	else
		free();
}
*/
void	cleanup_list(t_str_list **list)
{
	t_str_list	*temp;
	t_str_list	*prev;
	char		*s_temp;

	temp = *list;
	s_temp = NULL;
	while (temp->next != NULL)
	{
		s_temp = ft_strchr((const char *) temp->str, '\n');
		if (s_temp)
		{
			s_temp = ft_strdup(++s_temp);
			free(temp->str);
			temp->str = s_temp;
			*list = temp;
			return ;
		}
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	*list = temp;
	return ;
}

void	append_str(t_str_list **list, char *str)
{
	t_str_list	*last_node;
	t_str_list	*new_node;

	if ((*list)->empty)
	{
		(*list)->str = ft_strdup(str);
		(*list)->empty = 0;
		(*list)->next = NULL;
		return ;
	}
	new_node = malloc(sizeof(t_str_list));
	if (!new_node)
	{
		cleanup_list(&(*list));
		return ;
	}
	last_node = (*list);
	while (last_node->next)
		last_node = last_node->next;
	new_node->str = ft_strdup(str);
	new_node->empty = 0;
	new_node->next = NULL;
	last_node->next = new_node;
}

char	*ft_strcat(char *dest, char *src, size_t len)
{
	char	*ret;
	size_t	i;

	ret = dest;
	i = 0;
	while (*dest)
	{
		dest++;
		i++;
	}
	while (*src && i < len)
	{
		i++;
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;

	duplicate = NULL;
	i = 0;
	while (s[i] != '\0')
		i++;
	duplicate = malloc((sizeof(char) * i) + 1);
	if (duplicate == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		duplicate[i] = s[i];
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *) s);
}
