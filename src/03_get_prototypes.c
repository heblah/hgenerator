/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_get_prototypes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:57:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/16 16:56:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hgenerator.h"

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
	int	i;

	i = 0;
	while (*next_proto && *next_proto != '\t')
	{
		write(hfd, next_proto, 1);
		next_proto++;
		i++;
	}
	if (i < 4)
		write(hfd, "\t\t", 2);
	else if (i < 8)
		write(hfd, "\t", 1);
	else
		write(hfd, "\t", 1);
	next_proto++;
	write(hfd, next_proto, gnl_strlen(next_proto) - 1);
	write(hfd, ";\n", 2);
}

char	*join_names(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = NULL;
	if (ft_strlen(s1) + ft_strlen(s2))
		dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] && ft_strlen(s1) + ft_strlen(s2))
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && ft_strlen(s1) + ft_strlen(s2))
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}
