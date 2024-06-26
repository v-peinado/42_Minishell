/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:35:31 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

char	*extract_put(char *line)
{
	size_t	n;
	int		flag;
	char	*ret;
	char	*start;

	n = 0;
	flag = 0;
	while (*line && is_blank(*line))
		line++;
	start = line;
	if (*line == '\'' || *line == '\"')
	{
		changeflag(*line++, &flag);
		n++;
	}
	while (*line && (flag || (*line != '<' && *line != '>' && *line != ' ')))
	{
		if (*line == '\'' || *line == '\"')
			changeflag(*line, &flag);
		n++;
		line++;
	}
	ret = ft_substr(start, 0, n);
	return (ret);
}

char	*ex_input(char *str, t_cmd *c, int i)
{
	int	flag;

	flag = 0;
	if (*++str == '<')
	{
		c->in_redir_type[i] = ft_strdup("<<");
		str++;
	}
	else
		c->in_redir_type[i] = ft_strdup("<");
	while (*str && is_blank(*str))
		str++;
	if (*str != '>' || *str != '<')
		c->input[i] = extract_put(str);
	if (*str == '\'' || *str == '\"')
		changeflag(*str++, &flag);
	while (*str && (flag || (*str != '<' && *str != '>' && *str != ' ')))
	{
		if (*str == '\'' || *str == '\"')
			changeflag(*str, &flag);
		str++;
	}
	return (str);
}

char	*ex_output(char *str, t_cmd *c, int i)
{
	int	flag;

	flag = 0;
	if (*++str == '>')
	{
		c->out_redir_type[i] = ft_strdup(">>");
		str++;
	}
	else
		c->out_redir_type[i] = ft_strdup(">");
	while (*str && is_blank(*str))
		str++;
	if (*str != '<' || *str != '>')
		c->output[i] = extract_put(str);
	else
		ft_error("syntax error near unexpected token `>'");
	if (*str == '\'' || *str == '\"')
		changeflag(*str++, &flag);
	while (*str && (flag || (*str != '<' && *str != '>' && *str != ' ')))
	{
		if (*str == '\'' || *str == '\"')
			changeflag(*str, &flag);
		str++;
	}
	return (str);
}

char	*ex_arg(char *str, t_cmd *c, int i)
{
	int	flag;

	flag = 0;
	c->args[i] = extract_put(str);
	c->n_args++;
	if (*str == '\'' || *str == '\"')
		changeflag(*str++, &flag);
	while (*str && (flag || (*str != '<' && *str != '>' && *str != ' ')))
	{
		if (*str == '\'' || *str == '\"')
			changeflag(*str, &flag);
		str++;
	}
	return (str);
}
