/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:42:55 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/02 15:50:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hgenerator.h"

#define CHILD		0
#define FILE_BUF	500

int	main(int argc __attribute__((unused)), char **argv)
{
	char	**files_name;
	int		nbfiles;
	int		hfd;

	if (argc != 2)
	{
		printf("Please specify only one argument : the name of the header.\n");
		return (-1);
	}
	else if (isvalid_extension(*(argv + 1)) == 0)
	{
		printf("Please specify a '.h' entension.\n");
		return (-1);
	}
	nbfiles = 0;
	files_name = NULL;
	hfd = create_header(argv[1]);
	files_name = get_files_data(&nbfiles);
	header_writing(hfd, argv[1], files_name, nbfiles);
	freedata(files_name);
	return (0);
}

void	header_writing(int hfd, char *h_name, char **files_name, int nbfiles)
{
	header_protection(hfd, h_name);
	header_includes(hfd);
	header_prototypes(hfd, files_name, nbfiles);
	header_ending(hfd);
}

int	create_header(char *h_name)
{
	int	hfd;
	int	id;

	hfd = -1;
	id = fork();
	if (id == 0)
	{
		execl("/bin/rm", "rm", h_name, (char *) NULL);
	}
	else
	{
		wait(&id);
		hfd = open(h_name, O_CREAT | O_APPEND | O_RDWR, 0666);
		if (hfd == -1)
			exit(-1);
	}
	return (hfd);
}

void	freedata(char **files_name)
{
	int	i;

	i = 0;
	while (files_name[i])
	{
		free(files_name[i]);
		files_name[i] = NULL;
		i++;
	}
	free(files_name);
	files_name = NULL;
}

int	isvalid_extension(char *h_name)
{
	size_t	len;

	len = ft_strlen(h_name);
	if (ft_strncmp(".h", h_name + len - 2, 2) == 0)
		return (1);
	else if (ft_strncmp(".hpp", h_name + len - 4, 4) == 0)
		return (1);
	else
		return (0);
}
