/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:40 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/09 16:44:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r' )))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		n = n * 10 + nptr[i++] - '0';
	return (sign * n);
}
