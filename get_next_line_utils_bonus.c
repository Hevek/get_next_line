/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/02/10 22:19:05 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char) c)
	{
		if (!*s++)
			return (NULL);
	}
	if (*s == '\0')
		return (NULL);
	return ((char *) s);
}

size_t	get_line_size(t_str_list *list)
{
	size_t	len;
	size_t	i;

	len = 0;
	if (!list || !list->str)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str && list->str[i++])
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
void	cleanup_list(t_str_list **list, size_t error)
{
	t_str_list	*tmp;
	char		*str;
	char		*s_tmp;

	tmp = *list;
	str = NULL;
	if (*list)
		str = ft_strchr((*list)->str, '\n');
	while (*list)
	{
		str = ft_strchr((*list)->str, '\n');
		if (str && error == 0)
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

	if (!*s)
		return (NULL);
	duplicate = NULL;
	i = 0;
	while (s[i] != '\0')
		i++;
	duplicate = ft_calloc(i + 1, 1);
	if (duplicate == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		duplicate[i] = s[i];
	duplicate[i] = '\0';
	return (duplicate);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	alloc_size;
	int		i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > ((size_t) -1) / size)
		return (NULL);
	alloc_size = nmemb * size;
	ptr = malloc(alloc_size);
	if (!ptr)
		return (NULL);
	i = -1;
	while ((size_t)++i < alloc_size)
		((unsigned char *) ptr)[i] = '\0';
	return (ptr);
}
