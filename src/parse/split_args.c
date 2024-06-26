/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:28 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:49 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

int	ft_cw2(char const *s, char c)
{
	int	word;
	int	flag;

	word = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && (flag || *s != c))
			{
				if ((*s == '\"' || *s == '\''))
					changeflag(*s, &flag);
				s++;
			}
			word++;
		}
		else
			s++;
	}
	return (word);
}

static int	ft_size_word2(char const *s, char c, int index_s)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	while (s[index_s] && (flag || s[index_s] != c))
	{
		if ((s[index_s] == '\"' || s[index_s] == '\''))
			changeflag(*s, &flag);
		size++;
		index_s++;
	}
	return (size);
}

static void	ft_free2(char **strs, int index_strs)
{
	while (index_strs--)
		free(strs[index_strs]);
	free(strs);
}

char	**ft_split_args(char const *s, char c)
{
	int		index_s;
	char	**strs;
	int		size;
	int		index_strs;

	index_s = 0;
	index_strs = -1;
	strs = (char **)malloc((ft_cw2(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (++index_strs < ft_cw2(s, c))
	{
		while (s[index_s] == c)
			index_s++;
		size = ft_size_word2(s, c, index_s);
		strs[index_strs] = ft_substr(s, index_s, size);
		if (!strs[index_strs])
		{
			ft_free2(strs, index_strs);
			return (NULL);
		}
		index_s = size + index_s;
	}
	strs[index_strs] = NULL;
	return (strs);
}
