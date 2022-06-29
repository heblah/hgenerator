/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:52:48 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/22 11:03:59 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "hgenerator.h"

#define CHILD		0
#define FILE_BUF	500

char	**get_files_data(int *nbfiles)
{
	char	*str_name;
	char	**files_name;

	str_name = get_files_names();
	files_name = ft_split(str_name, '\n');
	free(str_name);
	while (files_name[*nbfiles])
		*nbfiles += 1;
	return (files_name);
}

char	*get_files_names(void)
{
	char	*files_name;
	int		rd;
	int		id;
	int		fd[2];

	rd = 1;
	pipe(fd);
	id = fork();
	files_name = NULL;
	if (id == CHILD)
	{
		if (child_process(fd) != 0)
			return (NULL);
	}
	else
	{
		wait(&id);
		files_name = parent_process(fd, rd, files_name);
	}
	return (files_name);
}

int	child_process(int *fd)
{
	if (close(fd[0]) == -1)
		return (1);
	if (dup2(fd[1], 1) == -1)
		return (2);
	if (execl("/bin/find", "find", ".", "-name", "*.c", (char *) NULL) == -1)
		return (3);
	return (0);
}

char	*parent_process(int *fd, int rd, char *files_name)
{
	char	*buffer;

	buffer = gnl_calloc(FILE_BUF + 1);
	if (close(fd[1]) == -1)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd[0], buffer, FILE_BUF);
		if (rd == -1)
		{
			free(files_name);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (rd > 0)
			files_name = ft_strjoin(files_name, buffer);
	}
	free(buffer);
	return (files_name);
}
