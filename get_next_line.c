/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/02/10 14:37:15 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

/* int	main(void)
{
	char	*line;
	int		fd;
	int		n;
	char	test;

	test = '2';
	if (test == '1')
	{
		fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/1char.txt",
				O_RDONLY);
	}
	else if (test == '2')
	{
		fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/only_nl.txt",
				O_RDONLY);
	}
	else if (test == '3')
	{
		fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/giant_line_nl.txt",
				O_RDONLY);
	}
	else if (test == '4')
	{
	fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/variable_nls.txt",
				O_RDONLY);
	}
	else
	{
		fd = open("test", O_RDONLY);
	}
	n = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("Line %d: %s", n++, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
} */
char	*get_next_line(int fd)
{
	static t_str_list	*list = NULL;
	char				*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	fill_list(&list, fd);
	line = transfer_line(list);
	cleanup_list(&list);
	if (!line)
		return (free(list), NULL);
	return (line);
}

/*  */
void	fill_list(t_str_list **list, int fd)
{
	int		b_read;
	char	*str;

	b_read = 1;
	str = NULL;
	while (str == NULL || !ft_strchr(str, '\n'))
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (cleanup_list(list));
		b_read = read(fd, str, BUFFER_SIZE);
		if (!b_read)
			return (free(str));
		str[BUFFER_SIZE] = '\0';
		append_str(list, str);
	}
}

void	append_str(t_str_list **list, char *str)
{
	t_str_list	*new;
	t_str_list	*last;

	new = malloc(sizeof(t_str_list));
	if (!new)
		return (cleanup_list(list));
	if (!*list)
		*list = new;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	new->str = str;
	new->next = NULL;
}

char	*transfer_line(t_str_list *list)
{
	char		*line;
	size_t		i;
	size_t		j;

	if (!list || !list->str)
		return (NULL);
	line = malloc(get_line_size(list) + 1);
	j = -1;
	while (list)
	{
		i = -1;
		while (list->str[++i])
		{
			line[++j] = list->str[i];
			if (list->str[i] == '\n')
			{
				line[++j] = '\0';
				return (line);
			}
		}
		list = list->next;
	}
	line[++j] = '\0';
	return (line);
}
