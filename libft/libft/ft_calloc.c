/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:48:31 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/11 13:05:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	size_t			i;
	const size_t	size_m = nmemb * size;

	i = 0;
	ptr = (void *)0;
	if (nmemb && size_m / nmemb != size)
		return ((void *)0);
	ptr = malloc(size_m);
	if (!ptr)
		return ((void *)0);
	while (i < size_m)
		*(ptr + i++) = '\0';
	return ((void *)ptr);
}
