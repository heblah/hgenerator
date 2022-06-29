/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:10:43 by hans              #+#    #+#             */
/*   Updated: 2022/06/22 17:12:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_calloc(size_t size)
{
	char	*s;
	size_t	i;

	s = malloc(size * sizeof(char));
	if (!s || !size)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(s + i) = *(s + i) & (~*(s + i));
		i++;
	}
	return ((char *)s);
}

char	*gnl_cat(t_flag *f, char *gnl, char *buffer)
{
	char	*d;

	d = gnl_calloc(gnl_strlen(gnl) + gnl_strlen(buffer) + 1);
	if (!d || (!gnl && !buffer))
	{
		free (gnl);
		return (NULL);
	}
	if (gnl)
	{
		d = gnl_cpy(f, d, gnl);
		free(gnl);
	}
	if (buffer)
		d = gnl_cpy(f, d, buffer);
	return (d);
}

char	*gnl_cpy(t_flag *f, char *dst, char *src)
{
	int	i;

	i = gnl_strlen(dst);
	while (*src)
	{
		*(dst + i) = *src;
		*src++ = '\0';
		if (f->eol == -1 && *(dst + i) == '\n')
			f->eol = i + 1;
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*gnl_memmove(t_flag *f, char *gnl)
{
	int	i;

	if (!gnl || f->eol == -1)
	{
		free(gnl);
		return (NULL);
	}
	i = 0;
	while (*(gnl + f->eol + i))
	{
		*(gnl + i) = *(gnl + f->eol + i);
		*(gnl + f->eol + i) = '\0';
		i++;
	}
	*(gnl + i) = '\0';
	return (gnl);
}
