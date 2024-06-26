/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:41:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:27 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

static int	check_pipe_bis(const char *line)
{
	int	flag;

	flag = 0;
	while (*line && is_blank(*line))
		line++;
	if (*line == '|')
		return (1);
	while (*line)
	{
		if (*line == '\'' || *line == '"')
			changeflag(*line, &flag);
		if (!flag && *line == '|')
		{
			line++;
			if (*line == '\'' || *line == '"')
				changeflag(*line, &flag);
			while (*line && is_blank(*line))
				line++;
			if (*line == '\0' || (!flag && *line == '|'))
				return (1);
		}
		line++;
	}
	return (0);
}

static int	check_quotes(char *str)
{
	char	quo;
	int		open;

	open = 0;
	while (*str)
	{
		if ((*str == '\'' || *str == '\"'))
		{
			if (!open)
			{
				open = 1;
				quo = *str;
			}
			else if (*str == quo)
				open = 0;
		}
		str++;
	}
	if (open)
		ft_error ("😡 ¡You didn't close your quotes you DingDong!\n");
	return (open);
}

static int	check_pipe(const char *line)
{
	if (!line)
		return (1);
	if (line[0] == '|')
	{
		ft_error("parse error near `|'\n");
		return (1);
	}
	if (line[ft_strlen(line) - 1] == '|')
	{
		ft_error("parse error near `|'\n");
		return (1);
	}
	if (check_pipe_bis(line))
	{
		ft_error("parse error near `|'\n");
		return (1);
	}
	return (0);
}

static int	check_redirections(const char *line)
{
	int	flag;

	flag = 0;
	while (*line)
	{
		if (*line == '\'' || *line == '"')
			changeflag(*line, &flag);
		if (!flag && *line == '>' && *(line + 1) == '<')
		{
			ft_error("syntax error '><'\n");
			return (1);
		}
		if (!flag && *line == '<' && *(line + 1) == '>')
		{
			ft_error("syntax error '<>'\n");
			return (1);
		}
		if (!flag && triple_pipe(line))
		{
			ft_error("syntax error 😉\n");
			return (1);
		}
		line++;
	}
	return (0);
}

int	check_errors(char *str, t_minsh *msh)
{
	int	e;

	e = 0;
	e = check_quotes(str);
	if (e)
	{
		msh->exit_code = 258;
		return (e);
	}
	e = check_pipe(str);
	if (e)
	{
		msh->exit_code = 258;
		return (e);
	}
	e = check_redirections(str);
	if (e)
	{
		msh->exit_code = 258;
		return (e);
	}
	return (e);
}
