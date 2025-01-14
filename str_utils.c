/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 04:14:16 by restevez          #+#    #+#             */
/*   Updated: 2025/01/14 04:25:02 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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


char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *) s);
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
