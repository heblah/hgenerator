/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:34:28 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/05 17:08:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	const char	*s;
	char		*d;

	i = 0;
	s = (const char *)src;
	d = (char *)dest;
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
