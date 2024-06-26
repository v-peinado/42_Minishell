/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:26 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:45 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

void	extract(t_cmd *c, char *str)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	j = -1;
	k = -1;
	while (*str && is_blank(*str))
		str++;
	while (*str)
	{
		if (*str == '<')
			str = ex_input(str, c, ++i);
		else if (*str == '>')
			str = ex_output(str, c, ++j);
		else
			str = ex_arg(str, c, ++k);
		while (*str && is_blank(*str))
			str++;
	}
}

t_cmd	**parsecmd(char *str, int ncmds)
{
	int		i;
	t_cmd	**cmds;
	char	**stcom;

	i = -1;
	stcom = commands(str, ncmds);
	cmds = ft_calloc (sizeof(t_cmd *), ncmds);
	while (++i < ncmds)
	{
		cmds[i] = new_cmd(stcom[i]);
		if (!cmds[i])
		{
			free_cmds(cmds, i + 1);
			ft_free_matrix((void **)stcom);
			ft_error("parse: command could not be made 😱\n");
			return (NULL);
		}
		extract (cmds[i], stcom[i]);
		if (cmds[i]->args[0])
			cmds[i]->command = ft_strdup(cmds[i]->args[0]);
		if (i > 0)
			cmds[i - 1]->next_cmd = cmds[i];
	}
	ft_free_matrix((void **)stcom);
	return (cmds);
}

int	count_cmds(char *str)
{
	int		n;
	int		flag;

	flag = 0;
	str = spaces(str);
	n = 0;
	while (*str)
	{
		if (*str != '|')
		{
			while (*str && (flag || *str != '|'))
			{
				if ((*str == '\"' || *str == '\''))
					changeflag(*str, &flag);
				str++;
			}
			n++;
		}
		else
			str++;
	}
	return (n);
}

int	parse(char *str, t_minsh *msh)
{
	if (check_errors(str, msh))
	{
		msh->n_cmds = 0;
		return (0);
	}
	msh->n_cmds = count_cmds(str);
	if (msh->n_cmds > MAXCMD)
	{
		ft_error("👮🛑 STOP! That's too many commands!\n");
		return (0);
	}
	else if (msh->n_cmds == 0)
	{
		msh->cmds = NULL;
		return (0);
	}
	else
	{
		msh->cmds = parsecmd(str, msh->n_cmds);
		if (msh->cmds)
			msh->cmds = expand_all(msh->cmds, msh->n_cmds, msh);
		else
			msh->n_cmds = 0;
		return (1);
	}
}
