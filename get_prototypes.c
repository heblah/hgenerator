/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prototypes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:57:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/01 12:06:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "hgenerator.h"

void	write_file_line(int hfd, char *files_name)
{
	int	width;

	width = 80 - 3;
	write (hfd, "\n/* ", 4);
	width -= 3;
	write(hfd, files_name, gnl_strlen(files_name));
	width -= gnl_strlen(files_name);
	write(hfd, " ", 1);
	width--;
	while (width-- > 0)
		write(hfd, "=", 1);
	write (hfd, " */\n", 4);
}

void	header_prototypes(int hfd, char **files_name, int nbfiles)
{
	int		i;
	int		cfd;
	int		eof;
	char	*next_proto;

	i = 0;
	next_proto = NULL;
	while (i < nbfiles)
	{
		write_file_line(hfd, files_name[i]);
		cfd = open(files_name[i], O_RDONLY);
		eof = 0;
		while (eof == 0)
		{
			next_proto = get_prototypes(cfd, &eof);
			if (next_proto)
			{
				write_prototype(hfd, next_proto);
				free(next_proto);
				next_proto = NULL;
			}
		}
		close(cfd);
		i++;
	}
}

char	*get_prototypes(int cfd, int *eof)
{
	char	*proto;

	proto = get_next_line(cfd);
	if (proto == NULL)
	{
		*eof = 1;
		return (NULL);
	}
	else if (*proto >= 97 && *proto <= 122
		&& ft_strncmp(proto, "static", gnl_strlen("static")) != 0
		&& ft_strncmp(proto, "int\tmain", gnl_strlen("int\tmain")) != 0
		&& ft_strncmp(proto, "/*", gnl_strlen("/*")) != 0
		&& ft_strncmp(proto, "//", gnl_strlen("//")) != 0)
		return (proto);
	else
	{
		free(proto);
		return (NULL);
	}
}

void	write_prototype(int hfd, char *next_proto)
{
	write(hfd, next_proto, gnl_strlen(next_proto) - 1);
	write(hfd, ";\n", 2);
}
