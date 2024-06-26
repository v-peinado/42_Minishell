/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:14:16 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:30 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

char	*quolim(char *st, size_t len, size_t i)
{
	size_t			j;
	char			quo;
	char			*sub_st[5];

	while (i < len && *(st + i) != '\'' && *(st + i) != '\"')
		i++;
	sub_st[0] = ft_substr(st, 0, i);
	quo = *(st + i);
	i++;
	j = 0;
	while ((i + j) < len && *(st + i + j) != quo)
		j++;
	sub_st[1] = ft_substr(st, i, j);
	sub_st[2] = ft_substr(st, i + j + 1, len - i - j);
	sub_st[3] = ft_strjoin(sub_st[0], sub_st[1]);
	sub_st[4] = ft_strjoin(sub_st[3], sub_st[2]);
	free (st);
	st = ft_strdup(sub_st[4]);
	free_this(sub_st);
	return (st);
}

int	n_expands(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (line && *line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '$' && (flag < 2 || *(line + 1) == ' '))
			n++;
		line++;
	}
	return (n);
}

int	n_quotes(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			changeflag(*line, &flag);
			if (flag == 0)
				n++;
		}
		line++;
	}
	return (n);
}

size_t	end_quote(char *st, size_t start)
{
	size_t	j;
	int		flag;

	j = 0;
	flag = 0;
	while (*(st + start + j))
	{
		if (*(st + start + j) == '\'' || *(st + start + j) == '\"')
		{
			changeflag(*(st + start + j), &flag);
			if (flag == 0)
				return (j);
		}
		j++;
	}
	return(j);
}

void	free_this(char *this[5])
{
	if (this[0])
		free(this[0]);
	if (this[1])
		free(this[1]);
	if (this[2])
		free(this[2]);
	if (this[3])
		free(this[3]);
	if (this[4])
		free(this[4]);
}
