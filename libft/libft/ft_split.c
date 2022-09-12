/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:58:19 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/09 16:24:44 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	ft_splitlen(char const *s, int *i, char c);
static void	freesplit(char **split, int words);

/*pour avoir 25lignes, i =i+len dans ft_splitlen puis s+i-len dans ft_strlcpy*/
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	words = count_words(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (++j < words)
	{
		len = ft_splitlen(s, &i, c);
		split[j] = malloc((len + 1) * sizeof(char));
		if (!split[j])
		{
			freesplit(split, words);
			return (NULL);
		}
		ft_strlcpy(split[j], s + i - len, len + 1);
	}
	split[j] = NULL;
	return (split);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static int	ft_splitlen(char const *s, int *i, char c)
{
	int	len;

	len = 0;
	while (s[*i] && s[*i] == c)
		*i += 1;
	while (s[*i + len] && s[*i + len] != c)
		len++;
	*i = *i + len;
	return (len);
}

static void	freesplit(char **split, int words)
{
	int	i;

	i = -1;
	while (++i <= words)
	{
		free(split[i]);
		split[i] = NULL;
	}
	free(split);
	split = NULL;
}
