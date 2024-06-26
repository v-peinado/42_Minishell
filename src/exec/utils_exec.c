/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:19 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/26 19:41:58 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

int	is_builtin2(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command, "echo", 5)
		|| !ft_strncmp(cmd->command, "pwd", 4)
		|| !ft_strncmp(cmd->command, "env", 4))
		return (1);
	return (0);
}

int	is_builtin1(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command, "cd", 3)
		|| !ft_strncmp(cmd->command, "export", 7)
		|| !ft_strncmp(cmd->command, "unset", 6)
		|| !ft_strncmp(cmd->command, "exit", 5))
		return (1);
	return (0);
}

void	exec_builtin(t_minsh *msh, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command, "echo", 5))
		ft_echo(msh, cmd->args);
	else if (!ft_strncmp(cmd->command, "cd", 3))
		ft_cd(cmd->args, msh);
	else if (!ft_strncmp(cmd->command, "pwd", 4))
		ft_pwd(msh);
	else if (!ft_strncmp(cmd->command, "export", 7))
		ft_export(msh, cmd);
	else if (!ft_strncmp(cmd->command, "unset", 6))
		ft_unset(msh, cmd);
	else if (!ft_strncmp(cmd->command, "env", 4))
		ft_env(msh);
	else if (!ft_strncmp(cmd->command, "exit", 5))
		ft_exit(msh, cmd);
}

char	*get_env_var(char *var, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == var[j] && env[i][j] != '=')
			j++;
		if (env[i][j] == '=' && var[j] == '\0')
			return (&env[i][j + 1]);
		i++;
	}
	return (NULL);
}

int	is_valid_command_in_path(t_cmd *cmd, char **env)
{
	char	**path;
	char	*tmp[2];
	int		i;

	i = -1;
	path = ft_split(get_env_var("PATH", env), ':');
	if (!path)
		return (0);
	while (path[++i])
	{
		tmp[0] = ft_strjoin(path[i], "/");
		tmp[1] = ft_strjoin(tmp[0], cmd->command);
		free(tmp[0]);
		if (access(tmp[1], F_OK) == 0)
		{
			free (cmd->command);
			cmd->command = ft_strdup(tmp[1]);
			free(tmp[1]);
			ft_free_matrix((void **)path);
			return (1);
		}
		free(tmp[1]);
	}
	ft_free_matrix((void **)path);
	return (0);
}
