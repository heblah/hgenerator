/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:04:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/18 18:01:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

/*structures de flags*/
typedef struct s_flag
{
	int	sharp;
	int	blank;
	int	plus;
}		t_f;

/*fonctions ft_print.c*/
int		ft_printf(const char *s, ...);
int		print_select(const char *s, va_list argp, int *count);

/*ft_puthex.c :*/
void	ft_ptr_to_hex(va_list argp, int *count);
void	ft_long_to_hex(va_list argp, int *count, char conv);
void	ft_puthex(unsigned long n, char *base, int *count);

/*ft_putnbr.c :*/
void	ft_int_to_nbr(va_list argp, int *count);
void	ft_uint_to_nbr(va_list argp, int *count);
void	ft_putnbr(long nb, int *count);

/*ft_putttxt.c :*/
void	ft_putchar(va_list argp, int *count);
void	ft_putstr(va_list argp, int *count);
#endif
