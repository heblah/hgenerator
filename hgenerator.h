/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgenerator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/22 12:25:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HGENERATOR_H
# define HGENERATOR_H

# include <sys/types.h>
# include <sys/wait.h>

/* main.c =================================================================== */
void	header_writing(int hfd, char *h_name, char **files_name, int nbfiles);
int		create_header(char *h_name);
void	freedata(char **files_name);

/* hgenerator.c ============================================================= */
void	header_protection(int fd, char *name);
void	header_includes(int fd);
char	*header_name(char *name);
int		ft_toupper(int c);
void	header_ending(int fd);

/* files_managing.c ========================================================= */
char	**get_files_data(int *nbfiles);
char	*get_files_names(void);
int		child_process(int *fd);
char	*parent_process(int *fd, int rd, char *files_name);

/* get_prototypes.c ========================================================= */
void	write_file_line(int fd, char *files_name);
void	header_prototypes(int hfd, char **files_name, int nbfiles);
char	*get_prototypes(int cfd, int *eof);
void	write_prototype(int hfd, char *next_proto);

/* hgen_utils_1.c =========================================================== */
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* ft_splic.c =============================================================== */
char	**ft_split(char const *s, char c);
#endif
