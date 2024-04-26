/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:16:21 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/26 19:40:25 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

void	ft_echo(t_minsh *msh, char **args)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "-n", 2) == 0)
		{
			flag = 1;
			i++;
			continue ;
		}
		printf("%s ", args[i]);
		i++;
	}
	if (!flag)
		printf("\n");
	msh->exit_code = 0;
}
