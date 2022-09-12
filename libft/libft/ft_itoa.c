/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:29:21 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/09 15:25:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_size(long nl, long *sign);
static void	ft_putnbr_str(long nl, char *itoa, long size);

char	*ft_itoa(int n)
{
	char	*itoa;
	long	sign;
	long	nl;
	long	size;

	nl = n;
	sign = 1;
	size = ft_size(nl, &sign);
	itoa = malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	ft_putnbr_str(nl, itoa, size - 1);
	itoa[size] = '\0';
	return (itoa);
}

static long	ft_size(long nl, long *sign)
{
	long	size;

	size = 0;
	if (nl < 0)
	{
		*sign = -1;
		size++;
		nl *= -1;
	}
	else if (nl == 0)
		return (1);
	while (nl != 0)
	{
		size++;
		nl /= 10;
	}
	return (size);
}

static void	ft_putnbr_str(long nl, char *itoa, long size)
{
	if (nl < 0)
	{
		itoa[0] = '-';
		nl *= -1;
	}
	if (nl > 9)
	{
		ft_putnbr_str(nl / 10, itoa, size - 1);
		itoa[size] = nl % 10 + '0';
	}
	else
		itoa[size] = nl % 10 + '0';
}
/*
int	main()
{
	int		n;
	char	*itoa;

	n = INT_MAX;
	itoa = ft_itoa(n);
	printf("%s", itoa);
	free(itoa);
	return (0);
}
*/
