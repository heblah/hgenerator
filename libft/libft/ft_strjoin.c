/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:27:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/12 14:48:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	while (s1 && s1[++i])
		dest[i] = s1[i];
	while (s2 && s2[++j])
		dest[i + j] = s2[j];
	while (i + j < len + 1)
		dest[i + j++] = '\0';
	return (dest);
}
