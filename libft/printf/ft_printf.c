/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/20 11:32:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	argp;
	int		count;

	count = 0;
	va_start(argp, s);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			count++;
		}
		else
		{
			print_select(s, argp, &count);
			s++;
		}
		s++;
	}
	va_end(argp);
	return (count);
}

int	print_select(const char *s, va_list argp, int *count)
{
	if (*s == '%' && *(s + 1) == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
	else if (*s == '%' && *(s + 1) == 'c')
		ft_putchar(argp, count);
	else if (*s == '%' && *(s + 1) == 's')
		ft_putstr(argp, count);
	else if (*s == '%' && (*(s + 1) == 'd' || *(s + 1) == 'i'))
		ft_int_to_nbr(argp, count);
	else if (*s == '%' && *(s + 1) == 'u')
		ft_uint_to_nbr(argp, count);
	else if (*s == '%' && *(s + 1) == 'p')
		ft_ptr_to_hex(argp, count);
	else if (*s == '%' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
		ft_long_to_hex(argp, count, *(s + 1));
	else
		return (-1);
	return (0);
}
