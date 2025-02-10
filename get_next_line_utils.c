/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/02/10 14:38:24 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *) s);
}

size_t	get_line_size(t_str_list *list)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i++])
			len++;
		list = list->next;
	}
	return (len);
}

/* cleanup_list(**list):
	t_str_list *tmp;
	char		*str;

	tmp = *list;
	str = NULL;
	while (we don't find '\n' and not end of the list)
	{
		tmp = list->next;
		str = ft_strchr(list->str, '\n');
		if (str)
		{
			append_str(list, str);
			tmp = list->next;
			free(list->str);
			free(list);
			list = tmp;
			return ;
		}
		free(list->str);
		free(list);
		list = tmp;
	}
*/
void	cleanup_list(t_str_list **list)
{
	t_str_list	*tmp;
	char		*str;
	char		*s_tmp;

	tmp = *list;
	if (*list)
		str = ft_strchr((*list)->str, '\n');
	while (*list)
	{
		str = ft_strchr((*list)->str, '\n');
		if (str)
		{
			s_tmp = (*list)->str;
			(*list)->str = ft_strdup(++str);
			free(s_tmp);
			str = NULL;
			return ;
		}
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
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
