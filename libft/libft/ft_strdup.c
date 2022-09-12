/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:08:04 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/07 18:00:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = -1;
	d = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!d)
		return ((void *)0);
	while (s[++i])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}
