/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttxt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:05:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/18 15:08:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(va_list argp, int *count)
{
	int	c;

	c = va_arg(argp, int);
	write(1, &c, sizeof(char));
	*count += 1;
}

void	ft_putstr(va_list argp, int *count)
{
	char	*s;

	s = (char *)va_arg(argp, int *);
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		while (*s)
		{
			write(1, s, sizeof(char));
			*count += 1;
			s++;
		}
	}
}
