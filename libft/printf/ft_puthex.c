/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:09:32 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/19 10:05:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_to_hex(va_list argp, int *count)
{
	char			*hex;
	unsigned long	n;

	hex = "0123456789abcdef";
	n = va_arg(argp, unsigned long);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		ft_puthex(n, hex, count);
	}
}

void	ft_long_to_hex(va_list argp, int *count, char conv)
{
	char			*hex;
	unsigned int	n;

	n = va_arg(argp, long);
	hex = NULL;
	if (conv == 'x')
		hex = "0123456789abcdef";
	else if (conv == 'X')
		hex = "0123456789ABCDEF";
	ft_puthex(n, hex, count);
}

void	ft_puthex(unsigned long n, char *base, int *count)
{
	if (n > 15)
	{
		ft_puthex(n / 16, base, count);
		ft_putchar_fd(base[n % 16], 1);
		*count += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*count += 1;
	}
}
