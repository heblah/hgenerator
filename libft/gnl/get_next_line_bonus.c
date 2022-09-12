/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:32:26 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/22 17:09:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*gnl[1024];
	char		*print_nl;
	t_flag		f;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	print_nl = NULL;
	f.eol = -1;
	gnl[fd] = get_gnl(&f, fd, gnl[fd]);
	print_nl = get_print_nl(&f, gnl[fd], print_nl);
	gnl[fd] = gnl_memmove(&f, gnl[fd]);
	if (gnl[fd] && *gnl[fd] == '\0')
	{
		free(gnl[fd]);
		gnl[fd] = NULL;
	}
	return (print_nl);
}

char	*get_gnl(t_flag *f, int fd, char *gnl)
{
	char	*buffer;
	int		rd;

	buffer = gnl_calloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(gnl);
		return (NULL);
	}
	rd = 1;
	while (f->eol == -1 && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (rd > 0)
			gnl = gnl_cat(f, gnl, buffer);
	}
	free(buffer);
	return (gnl);
}

char	*get_print_nl(t_flag *f, char *gnl, char *print_nl)
{
	int		i;

	if (!gnl)
		return (NULL);
	print_nl = gnl_calloc(gnl_strlen(gnl) + 1);
	if (!print_nl)
		return (NULL);
	i = 0;
	while (*(gnl + i) && *(gnl + i) != '\n')
	{
		*(print_nl + i) = *(gnl + i);
		*(gnl + i) = '\0';
		i++;
	}
	if (*(gnl + i) == '\n')
	{
		*(print_nl + i++) = '\n';
		f->eol = i;
	}
	*(print_nl + i) = '\0';
	return (print_nl);
}
