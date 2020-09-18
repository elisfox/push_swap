/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:07:56 by bcolossu          #+#    #+#             */
/*   Updated: 2019/10/16 19:08:00 by bcolossu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ch_segment(char *segment, char **line)
{
	char	*pointer;

	pointer = NULL;
	if (segment)
		if ((pointer = ft_strchr(segment, '\n')))
		{
			*pointer = '\0';
			*line = ft_strdup(segment);
			ft_strcpy(segment, ++pointer);
		}
		else
		{
			*line = ft_strdup(segment);
			ft_strclr(segment);
		}
	else
		*line = ft_strnew(1);
	return (pointer);
}

int		join_line(const int fd, char **line, char **segment)
{
	char	buf[BUFF_SIZE + 1];
	char	*pointer;
	int		was_read;
	char	*tmp;

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	pointer = ch_segment(*segment, line);
	while (!pointer && (was_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[was_read] = '\0';
		if ((pointer = ft_strchr(buf, '\n')))
		{
			*pointer = '\0';
			*segment = ft_strdup(++pointer);
		}
		else
			*segment = "\0";
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strdel(&tmp);
	}
	return (was_read || ft_strlen(*segment) || (ft_strlen(*line))) ? 1 : 0;
}

t_gnl	*add_list(const int fd)
{
	t_gnl	*add;

	if (!(add = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	add->fd = fd;
	add->segment = NULL;
	add->next = NULL;
	return (add);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*first;
	t_gnl			*tmp;

	if (first == NULL)
		first = add_list(fd);
	tmp = first;
	while (tmp->fd != fd)
	{
		if (!tmp->next)
			tmp->next = add_list(fd);
		tmp = tmp->next;
	}
	return (join_line(tmp->fd, line, &tmp->segment));
}
