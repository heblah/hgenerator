/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:44:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/02 14:15:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./ft_atoi.c ============================================================== */
int		ft_atoi(const char *nptr);

/* ./ft_bzero.c ============================================================= */
void	ft_bzero(void *s, size_t n);

/* ./ft_calloc.c ============================================================ */
void	*ft_calloc(size_t nmemb, size_t size);

/* ./ft_isalnum.c =========================================================== */
int		ft_isalnum(int c);

/* ./ft_isalpha.c =========================================================== */
int		ft_isalpha(int c);

/* ./ft_isdigit.c =========================================================== */
int		ft_isdigit(int c);

/* ./ft_itoa.c ============================================================== */
char	*ft_itoa(int n);

/* ./ft_memcmp.c ============================================================ */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* ./ft_memcpy.c ============================================================ */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* ./ft_memmove.c =========================================================== */
void	*ft_memmove(void *dest, const void *src, size_t n);

/* ./ft_memset.c ============================================================ */
void	*ft_memset(void *s, int c, size_t n);

/* ./ft_putchar_fd.c ======================================================== */
void	ft_putchar_fd(char c, int fd);

/* ./ft_putendl_fd.c ======================================================== */
void	ft_putendl_fd(char *s, int fd);

/* ./ft_putnbr_fd.c ========================================================= */
void	ft_putnbr_fd(int n, int fd);

/* ./ft_putstr_fd.c ========================================================= */
void	ft_putstr_fd(char *s, int fd);

/* ./ft_split.c ============================================================= */
char	**ft_split(char const *s, char c);

/* ./ft_strchr.c ============================================================ */
char	*ft_strchr(const char *s, int c);

/* ./ft_strdup.c ============================================================ */
char	*ft_strdup(const char *s);

/* ./ft_strjoin.c =========================================================== */
char	*ft_strjoin(char const *s1, char const *s2);

/* ./ft_strlcpy.c =========================================================== */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* ./ft_strlen.c ============================================================ */
size_t	ft_strlen(const char *s);

/* ./ft_strcmp.c ============================================================ */
int		ft_strcmp(const char *s1, const char *s2);

/* ./ft_strncmp.c =========================================================== */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ./ft_strnstr.c =========================================================== */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* ./ft_strrchr.c =========================================================== */
char	*ft_strrchr(const char *s, int c);

/* ./ft_strtrim.c =========================================================== */
char	*ft_strtrim(char const *s1, char const *set);

/* ./ft_substr.c ============================================================ */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ./ft_tolower.c =========================================================== */
int		ft_tolower(int c);

/* ./ft_toupper.c =========================================================== */
int		ft_toupper(int c);
#endif
