/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:53:13 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:40:28 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

void	ft_env(t_minsh *msh)
{
	size_t	i;

	i = -1;
	while (msh->env[++i])
	{
		if (ft_strchr(msh->env[i], '='))
			printf("%s\n", msh->env[i]);
	}
	msh->exit_code = 0;
}
