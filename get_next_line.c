/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/01/15 03:54:10 by restevez         ###   ########.fr       */
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
[] max of 10 function because number of turn in files;
[] explore corner cases, run testers;
 */
int	main(int argc, char *argv[])
{
	char	*str;
	int		fd;
	int		i;

	str = NULL;
	if (argc < 2)
		return (1);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	printf("Line one: %s", get_next_line(fd));
	// printf("Line two: %s", get_next_line(fd));
	return (0);
}

char	*get_next_line(int fd)
{
	static t_str_list	*buff = NULL;
	char				*next_line;

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
			break ;
		str[BUFFER_SIZE] = '\0';
		append_str(&(*buff), str);
	}
	free(str);
	str = get_line((*buff));
	cleanup_list(&(*buff));
	if (!str)
		return (NULL);
	return (str);
}

char	*get_line(t_str_list *list)
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
		while (tmp->str[++i] && tmp->str[i - 1] != '\n')
			len++;
		tmp = tmp->next;
	}
	line = fill_line(&list, len);
	if (!line)
		return (NULL);
	return (line);
}
