/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/02/07 05:49:46 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

/* get_next_line((int) file descriptor):
Return Value:
	Read line: correct behavior
	NULL: there is nothing else to read, or an error
	occurred
Please note that the returned line should include the terminating \n
character if it is found (Hence, if the file does not terminate in \n, there's
nothing to include at the EOL).
*/
/*
TO-DOs:
[x] max of 10 function because number of turn in files;
[] explore corner cases, run testers;
 */
int	main(int argc, char *argv[])
{
	char	*str;
	int		fd;
	int		j;

	str = NULL;
	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	j = 0;
	while (str)
	{
		printf("Line %d: %s", ++j, str);
		str = get_next_line(fd);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_str_list	*buff = NULL;
	char				*next_line;

	if (fd <= 0)
		return (NULL);
	next_line = get_strings(fd, &buff);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}

char	*get_strings(int fd, t_str_list **buff)
{
	int					chr_read;
	char				*str;

	str = malloc(BUFFER_SIZE + 1);
	chr_read = 1;
	if (!(*buff))
	{
		(*buff) = malloc(sizeof(t_str_list));
		(*buff)->empty = 1;
	}
	while (!ft_strchr(str, '\n'))
	{
		chr_read = read(fd, str, BUFFER_SIZE);
		if (chr_read == -1 || chr_read == 0)
			return (free(str), cleanup_list(&(*buff)), NULL);
		str[BUFFER_SIZE] = '\0';
		append_str(&(*buff), str);
	}
	free(str);
	str = ft_get_line((*buff));
	cleanup_list(&(*buff));
	if (!str)
		return (free(str), NULL);
	return (str);
}

char	*ft_get_line(t_str_list *list)
{
	t_str_list	*tmp;
	size_t		len;
	char		*line;
	int			i;

	tmp = list;
	len = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i] && tmp->str[i] != '\n')
			len++;
		if (tmp->str[i] == '\n')
		{
			len++;
			break ;
		}
		tmp = tmp->next;
	}
	line = fill_line(&list, len);
	if (!line)
		return (NULL);
	return (line);
}

/*
	full string

	allocate the space for full string
	while (current node exists)
	{
		concatenate (full string + node->string)
		if (this is the last node)
		{
			while (this char exists AND this char is not \n)
				run through node->string
			if (we got to the \n)
			{
				go to the next char in node->str
				this node->str will be empty now
				we add the rest of this string to a new node
			}
		}
	}
*/
char	*fill_line(t_str_list **list, size_t len)
{
	char		*str;
	size_t		str_len;

	str = malloc(len + 1);
	str_len = 0;
	while ((*list))
	{
		ft_strcat(str, (*list)->str, len);
		if ((*list)->next == NULL)
		{
			while (*((*list)->str) && *((*list)->str) != '\n' && ++str_len)
				(*list)->str++;
			if (*((*list)->str) == '\n' && str_len < BUFFER_SIZE)
			{
				(*list)->str++;
				(*list)->empty = 1;
				append_str(&(*list), (*list)->str);
				(*list)->next = NULL;
				return (str);
			}
		}
		(*list) = (*list)->next;
	}
	return (str);
}
