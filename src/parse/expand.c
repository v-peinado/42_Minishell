/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:08 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:34 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

char	*eliminate_quotes(char *st)
{
	char			*ret;
	int				n_quo;
	size_t			start;
	size_t			end;

	start = 0;
	n_quo = n_quotes(st);
	if (n_quo == 0)
		return (st);
	while (n_quo--)
	{
		end = end_quote(st, start);
		ret = quolim(st, ft_strlen(st), start);
		start = end - 1;
		st = ret;
	}
	return (st);
}

char	*find_env(t_minsh *msh, char *find, size_t len)
{
	int	i;

	i = 0;
	if (ft_strncmp(find, "?", 1) == 0)
		return (ft_itoa(msh->exit_code));
	while (msh->env[i])
	{
		if (ft_strncmp(msh->env[i], find, len) == 0)
			return (extract_env(msh->env[i]));
		i++;
	}
	return (NULL);
}

char	*replace(char *cmd, t_minsh *msh, size_t i)
{
	char	*subs[5];
	char	*ret;
	size_t	j;
	size_t	k;

	k = 0;
	subs[0] = ft_substr(cmd, 0, i);
	i++;
	j = 0;
	while (*(cmd + i + j) && ft_isalnum(*(cmd + i + j)))
		j++;
	subs[1] = ft_substr(cmd, i, j);
	if (ft_strlen(subs[1]) == 0)
		subs[2] = ft_strdup("$");
	else
		subs[2] = find_env(msh, subs[1], ft_strlen(subs[1]));
	while (*(cmd + i + j + k) != '\0')
		k++;
	subs[3] = ft_substr(cmd, i + j, k);
	subs[4] = ft_strjoin(subs[0], subs[2]);
	ret = ft_strjoin(subs[4], subs[3]);
	free_this(subs);
	return (ret);
}

char	*expand_this(char *str, t_minsh *msh)
{
	size_t	i;
	int		n;
	int		flag;
	char	*ret;

	i = 0;
	n = n_expands(str);
	flag = 0;
	if (n == 0)
		return (eliminate_quotes(str));
	while (n--)
	{
		while (*(str + i) && (*(str + i) != '$' || flag == 2))
		{
			if (*(str + i) == '\'' || *(str + i) == '\"')
				changeflag(*(str + i), &flag);
			i++;
		}
		ret = replace (str, msh, i);
		free (str);
		str = ret;
		i = 0;
	}
	return (eliminate_quotes(str));
}

t_cmd	**expand_all(t_cmd **cmd, int n_cmds, t_minsh *msh)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n_cmds)
	{
		j = -1;
		while (cmd[i]->input[++j])
			cmd[i]->input[j] = expand_this(cmd[i]->input[j], msh);
		j = -1;
		while (cmd[i]->output[++j])
			cmd[i]->output[j] = expand_this(cmd[i]->output[j], msh);
		j = -1;
		while (cmd[i]->args[++j])
			cmd[i]->args[j] = expand_this(cmd[i]->args[j], msh);
		if (cmd[i]->command)
			cmd[i]->command = expand_this(cmd[i]->command, msh);
	}
	return (cmd);
}
