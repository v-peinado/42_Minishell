/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:26:17 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:40:53 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

int	insetenv(char *str, char **args, int n_args)
{
	int	i;

	i = -1;
	if (n_args > 1)
	{
		while (++i < n_args)
		{
			if (ft_strncmp(str, args[i], eq(str)) == 0)
				return (1);
		}
	}
	return (0);
}

void	ft_unset(t_minsh *msh, t_cmd	*cmd)
{
	char	**newenv;
	size_t	i;
	size_t	j;

	newenv = ft_calloc(ft_strarrlen(msh->env), sizeof(char *));
	if (!newenv)
	{
		ft_error("malloc error. Upsies!");
		msh->exit_code = 1;
		return ;
	}
	i = -1;
	j = -1;
	while (msh->env[++i])
	{
		if (!insetenv(msh->env[i], cmd->args, cmd->n_args))
			newenv[++j] = ft_strdup(msh->env[i]);
	}
	ft_free_matrix((void **)msh->env);
	msh->env = newenv;
	msh->exit_code = 0;
}
