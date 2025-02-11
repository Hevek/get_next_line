/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/02/11 19:40:46 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

/* #include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*str;
	int		fd;
	int		n;
	char	test;
	size_t	end;

	end = 1;
	if (argc < 1)
		return (1);
	while (end)
	{
		n = 1;
		test = '0' + end;
		if (argc == 2)
			test = argv[1][0];
		printf("=======Test %c=======\n\n", test);
		if (test == '1')
		{
			fd = open(
	"/home/hevek/francinette/tests/get_next_line/fsoares/read_error.txt",
					O_RDONLY);
			line = get_next_line(fd);
			printf("Line %d: %s", n++, line);
			free(line);
			line = get_next_line(fd);
			printf("Line %d: %s", n++, line);
			free(line);
			if (BUFFER_SIZE > 100) {
				char *temp;
				do {
					temp = get_next_line(fd);
					free(temp);
				} while (temp != NULL);
			}
			line = get_next_line(fd);
			printf("Line %d: %s", n++, line);
			free(line);
			close(fd);
			end++;
			printf("<- File Ended\n\n\n\n==END_OF_TEST==\n\n");
			if (argc == 2)
				return (0);
			continue ;
		}
		else if (test == '2')
		{
			fd = open(
	"/home/hevek/francinette/tests/get_next_line/fsoares/one_line_no_nl.txt",
					O_RDONLY);
		}
		else if (test == '3')
		{
			fd = open(
	"/home/hevek/francinette/tests/get_next_line/fsoares/multiple_nl.txt",
					O_RDONLY);
		}
		else if (test == '4')
		{
		fd = open(
	"/home/hevek/francinette/tests/get_next_line/fsoares/variable_nls.txt",
					O_RDONLY);
		}
		else if (test == '5')
		{
		fd = open(
	"/home/hevek/francinette/tests/get_next_line/fsoares/1char.txt",
					O_RDONLY);
		}
		else
		{
			fd = open("test", O_RDONLY);
		}
		line = get_next_line(fd);
		while (line)
		{
			printf("Line %d: %s", n++, line);
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		if (test == '3')
		{
			line = get_next_line(fd);
			printf("Line: %d: %s", n, line);
		}
		close(fd);
		if (end == 7)
			break ;
		end++;
		if (line == NULL)
			printf("<- File Ended\n");
		printf("\n\n\n==END_OF_TEST==\n\n");
		if (argc == 2)
			return (0);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_str_list	*list = NULL;
	char				*line;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (cleanup_list(&list, 1), NULL);
	line = fill_list(&list, fd);
	if (!line)
		return (cleanup_list(&list, 1), NULL);
	return (line);
}

char	*get_strings(int fd, t_str_list **buff)
{
	char				*str;

	str = malloc(BUFFER_SIZE + 1);
	if (!(*buff))
	{
		(*buff) = malloc(sizeof(t_str_list));
		(*buff)->empty = 1;
	}
	while (!ft_strchr(str, '\n'))
	{
		if (read(fd, str, BUFFER_SIZE) <= 0)
			return (free(str), destroy_list(&(*buff), NULL, NULL), NULL);
		str[BUFFER_SIZE] = '\0';
		append_str(&(*buff), str);
	}
	return (transfer_line(list));
}

void	append_str(t_str_list **list, char *str)
{
	t_str_list	*new;
	t_str_list	*last;

	new = ft_calloc(sizeof(t_str_list), 1);
	if (!new)
		return (free(str), cleanup_list(list, 1));
	if (!*list)
		*list = new;
	else if ((*list)->str == NULL)
	{
		cleanup_list(list, 0);
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

char	*ft_get_line(t_str_list *list)
{
	t_str_list	*tmp;

	if (!*list || !(*list)->str)
		return (cleanup_list(list, 1), NULL);
	line = ft_calloc(get_line_size(*list) + 1, 1);
	if (!line)
		return (free(line), cleanup_list(list, 1), NULL);
	j = -1;
	tmp = *list;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i])
		{
			line[++j] = tmp->str[i];
			if (tmp->str[i] == '\n')
				return (cleanup_list(list, 0), line[++j] = '\0', line);
		}
		tmp = tmp->next;
	}
	line[++j] = '\0';
	return (cleanup_list(list, 0), line);
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
			if (*((*list)->str) == '\n')
			{
				(*list)->str++;
				(*list)->empty = 1;
				append_str(&(*list), (*list)->str);
				(*list)->next = NULL;
				(*list) = (*list)->next;
				continue ;
			}
		}
		(*list) = (*list)->next;
	}
	return (str);
}

void	clean_list(t_str_list **list)
{
	t_str_list	*last;
	t_str_list	*cleaned;
	size_t		i;
	size_t		j;
	char		*str;

	str = malloc(BUFFER_SIZE + 1);
	cleaned = malloc(sizeof(t_str_list));
	if (str == NULL || cleaned == NULL)
		return (free(str), free(cleaned), destroy_list(&(*list), NULL, NULL));
	last = *list;
	while (last->next)
		last = last->next;
	i = 0;
	j = 0;
	while (last->empty == 0 && last->str[i] != '\n')
		i++;
	while (last->str[i] && last->str[++i])
		str[j++] = last->str[i];
	str[j] = '\0';
	cleaned->str = str;
	cleaned->empty = 0;
	cleaned->next = NULL;
	destroy_list(list, cleaned, str);
}
