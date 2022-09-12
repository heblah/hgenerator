/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/09 14:51:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	2000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

/* structures =============================================================== */
typedef struct e_flag
{
	int	eol;
}	t_flag;

/* get_next_line.c ========================================================== */
char	*get_next_line(int fd);
char	*get_gnl(t_flag *f, int fd, char *gnl);
char	*get_print_nl(t_flag *f, char *gnl, char *print_nl);

/* get_next_line_utils.c ==================================================== */
char	*gnl_calloc(size_t size);
char	*gnl_cat(t_flag *f, char *gnl, char *buffer);
char	*gnl_cpy(t_flag *f, char *dst, char *src);
int		gnl_strlen(char *s);
char	*gnl_memmove(t_flag *f, char *gnl);
#endif
