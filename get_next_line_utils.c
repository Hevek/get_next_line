/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:23:46 by restevez          #+#    #+#             */
/*   Updated: 2025/02/11 19:47:52 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
