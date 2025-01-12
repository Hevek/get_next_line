/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/01/12 12:13:06 by restevez         ###   ########.fr       */
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
	get_next_line(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*next_line;

	next_line = get_line(fd);
	if (next_line == NULL)
		return (NULL);
	while (next_line)
		write(1, next_line++, 1);
	return ("\0");
}

char	*get_line(int fd)
{
	static t_str_list	*buff;
	char				*str;

	str = malloc(BUFFER_SIZE + 1);
	while (read(fd, str, BUFFER_SIZE))
	{
		append_str(&buff, str);
		free(str);
	}
	get_str(buff);
	return (str);
}

char	*get_str(t_str_list *list)
{
	t_str_list	*tmp;
	size_t		len;
	char		*str;
	int			i;

	tmp = list;
	len = 0;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i])
			len++;
		tmp = tmp->next;
	}
	str = fill_str(list, len);
	write(1, str, len);
	return (str);
}
