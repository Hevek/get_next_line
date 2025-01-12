/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/01/12 19:49:00 by restevez         ###   ########.fr       */
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

	next_line = get_strings(fd);
	if (next_line == NULL)
		return (NULL);
	while (next_line)
		write(1, next_line++, 1);
	free(next_line);
	return ("\0");
}

char	*get_strings(int fd)
{
	static t_str_list	*buff = NULL;
	int					chr_read;
	char				*str;

	str = malloc(BUFFER_SIZE + 1);
	chr_read = 1;
	buff = malloc(sizeof(t_str_list));
	buff->empty = 1;
	while (!ft_strchr(str, '\n'))
	{
		chr_read = read(fd, str, BUFFER_SIZE);
		if (chr_read == -1 || chr_read == 0)
			break ;
		str[BUFFER_SIZE] = '\0';
		append_str(&buff, str);
	}
	// write(1, str, BUFFER_SIZE); get_line(buff)
	return (NULL);
}

/* char	*get_line(t_str_list *list)
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
		while (tmp->str[++i])
			len++;
		tmp = tmp->next;
	}
	line = fill_line(list, len);
	write(1, line, len);
	return (line);
	return (NULL);
}
 */
