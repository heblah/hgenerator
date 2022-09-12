/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:51:14 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/20 12:22:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_to_nbr(va_list argp, int *count)
{
	long	d;

	d = va_arg(argp, int);
	if (d < 0)
	{
		write(1, "-", 1);
		d *= -1;
		*count += 1;
	}
	ft_putnbr(d, count);
}

void	ft_uint_to_nbr(va_list argp, int *count)
{
	long	d;

	d = va_arg(argp, unsigned int);
	ft_putnbr(d, count);
}

void	ft_putnbr(long nb, int *count)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putchar_fd(nb % 10 + '0', 1);
		*count += 1;
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		*count += 1;
	}
}
