/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/10 09:04:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = -1;
	if (!*little)
		return ((char *)big);
	while (big[++i] && len > 0)
	{
		k = 0;
		while ((big[i + k] || little[k]) && i + k < len
			&& big[i + k] == little[k])
		{
			k++;
			if (!little[k])
				return ((char *)(big + i));
		}
	}
	return ((void *)0);
}
