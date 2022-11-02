/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hgenerator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/02 14:46:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HGENERATOR_H
# define HGENERATOR_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/ft_libft.h"

/* main.c =================================================================== */
void	header_writing(int hfd, char *h_name, char **files_name, int nbfiles);
int		create_header(char *h_name);
void	freedata(char **files_name);
int		isvalid_extension(char *h_name);

/* hgenerator.c ============================================================= */
void	header_protection(int fd, char *name);
void	header_includes(int fd);
char	*header_name(char *name);
void	header_ending(int fd);

/* files_managing.c ========================================================= */
char	**get_files_data(int *nbfiles);
char	*get_files_names(void);
int		child_process(int *fd);
char	*parent_process(int *fd, int rd, char *files_name);
char	**ft_sort(char **split);

/* get_prototypes.c ========================================================= */
void	write_file_line(int fd, char *files_name);
void	header_prototypes(int hfd, char **files_name, int nbfiles);
char	*get_prototypes(int cfd, int *eof);
void	write_prototype(int hfd, char *next_proto);
char	*join_names(char *s1, char *s2);
#endif
