/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/02/10 19:46:43 by restevez         ###   ########.fr       */
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

	test = '3';
	if (test == '1')
	{
		fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/gnlTester/tests/41_no_nl",
				O_RDONLY);
	}
	else if (test == '2')
	{
		fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/one_line_no_nl.txt",
				O_RDONLY);
	}
	else if (test == '3')
	{
		fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/multiple_nl.txt",
				O_RDONLY);
	}
	else if (test == '4')
	{
	fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/variable_nls.txt",
				O_RDONLY);
	}
	else if (test == '5')
	{
	fd = open(
"/nfs/homes/restevez/francinette/tests/get_next_line/fsoares/1char.txt",
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
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	line = fill_list(&list, fd);
	if (!line)
		return (cleanup_list(&list), free(list), NULL);
	cleanup_list(&list);
	return (line);
}

/*  */
char	*fill_list(t_str_list **list, int fd)
{
	int		b_read;
	char	*str;

	b_read = 1;
	str = NULL;
	while (b_read != 0 && !ft_strchr(str, '\n'))
	{
		str = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!str)
			return (cleanup_list(list), NULL);
		b_read = read(fd, str, BUFFER_SIZE);
		if (!b_read)
			return (free(str), transfer_line(list));
		str[BUFFER_SIZE] = '\0';
		append_str(list, str);
	}
	return (transfer_line(list));
}

void	append_str(t_str_list **list, char *str)
{
	t_str_list	*new;
	t_str_list	*last;

	new = ft_calloc(sizeof(t_str_list), 1);
	if (!new)
		return (free(str), cleanup_list(list));
	if (!*list)
		*list = new;
	else if ((*list)->str == NULL)
	{
		free(*list);
		*list = new;
	}
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

char	*transfer_line(t_str_list **list)
{
	char		*line;
	size_t		i;
	size_t		j;
	t_str_list	*tmp;

	line = ft_calloc(get_line_size(*list) + 1, 1);
	if (!line || !*list || !(*list)->str)
		return (free(line), cleanup_list(list), NULL);
	j = -1;
	tmp = *list;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i])
		{
			line[++j] = tmp->str[i];
			if (tmp->str[i] == '\n')
			{
				return (line[++j] = '\0', line);
			}
		}
		tmp = tmp->next;
	}
	line[++j] = '\0';
	return (line);
}
