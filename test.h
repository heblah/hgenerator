#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./files_managing.c ======================================================= */
char	**get_files_data(int *nbfiles);
char	*get_files_names(void);
int	child_process(int *fd);
char	*parent_process(int *fd, int rd, char *files_name);
char	**ft_sort(char **split);

/* ./ft_split.c ============================================================= */
char	**ft_split(char const *s, char c);

/* ./get_next_line_bonus.c ================================================== */
char	*get_next_line(int fd);
char	*get_gnl(t_flag *f, int fd, char *gnl);
char	*get_print_nl(t_flag *f, char *gnl, char *print_nl);

/* ./get_next_line_utils_bonus.c ============================================ */
char	*gnl_calloc(size_t size);
char	*gnl_cat(t_flag *f, char *gnl, char *buffer);
char	*gnl_cpy(t_flag *f, char *dst, char *src);
int	gnl_strlen(char *s);
char	*gnl_memmove(t_flag *f, char *gnl);

/* ./get_prototypes.c ======================================================= */
void	write_file_line(int hfd, char *files_name);
void	header_prototypes(int hfd, char **files_name, int nbfiles);
char	*get_prototypes(int cfd, int *eof);
void	write_prototype(int hfd, char *next_proto);

/* ./hgen_utils_1.c ========================================================= */
char	*ft_strjoin(char *s1, char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	ft_strcmp(const char *s1, const char *s2);

/* ./hgenerator.c =========================================================== */
void	header_protection(int fd, char *name);
void	header_includes(int fd);
char	*header_name(char *name);
int	ft_toupper(int c);
void	header_ending(int fd);

/* ./main.c ================================================================= */
void	header_writing(int hfd, char *h_name, char **files_name, int nbfiles);
int	create_header(char *h_name);
void	freedata(char **files_name);
#endif
