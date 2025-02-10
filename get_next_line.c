/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 07:18:07 by restevez          #+#    #+#             */
/*   Updated: 2025/02/10 04:18:14 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	static *list;
	char	*line;

	if (fd < 0 OR BUF_SIZE <=  OR read(0) retuns < 0)
		return (NULL);
	fill_list();
*/
char	*get_next_line(int fd)
{

}

/*
	int		n_read;
	char	*str;

	while (we don't find newline)
	{
		allocate BUFFER_SIZE + 1 for str;
			allocate_error_treatment
		n_read = read(into str);
		if (!n_read)
			free(str) and return ;
		str[BUFFER_SIZE] = '\0';
		append_str(list, str);
	}
*/
void	fill_list()
{

}

/*
	t_str_list	*new;
	t_str_list	*last;

	last = get_last;
	new = allocate(t_str_list);
		allocate_error_treatment
	if (last == NULL)	
		*list = new;
	else
		last->next = new;
	new->str = str;
	new->next = NULL;
*/
void	append_str()
{
	
}

/* fill_line(list)
	int		len;
	char	*line;

	if (list == NULL)
		return (NULL);
	len = get_line_len();
	line = allocate (len + 1);
		allocate_error_treatment
	transfer_line(list, line);
	return (line);
*/
char	*fill_line()
{

}

/* transfer_line(list, str):
	int	i;
	int	j;

	if (list == NULL)
		return ;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->str[j])
		{
			if (list->str[j] == '\n')
			{
				str[i++] = '\n';
				str[i] = '\0';
				return ;
			}
			str[i++] = list->str[j++];
		}
		list = list->next;
	}
	str[i] = '\0';
*/
void	transfer_line()
{
	
}