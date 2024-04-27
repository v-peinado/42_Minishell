/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:59:18 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:42 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

int	triple_pipe(const char *line)
{
	if ((*line == '>' && *(line + 1) == '>')
		&& (*(line + 2) == '>' || *(line + 2) == '<'))
		return (1);
	if ((*line == '<' && *(line + 1) == '<')
		&& (*(line + 2) == '>' || *(line + 2) == '<'))
		return (1);
	return (0);
}

int	is_redirection(const char *c)
{
	if (*c == '<' || *c == '>')
	{
		c++;
		if (*c == '<' || *c == '>')
			return (2);
		else
			return (1);
	}
	return (0);
}

int	is_quote(const char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

int	n_output(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '>' && !flag)
		{
			if (*(line + 1) == '>')
				line++;
			n++;
		}
		line++;
	}
	return (n);
}

int	n_input(char *line)
{
	int		flag;
	int		n;

	flag = 0;
	n = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		if (*line == '<' && !flag)
		{
			if (*(line + 1) == '<')
				line++;
			n++;
		}
		line++;
	}
	return (n);
}
