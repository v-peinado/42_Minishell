/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:51:19 by ffons-ti          #+#    #+#             */
/*   Updated: 2024/04/26 19:40:39 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

void	ft_pwd(t_minsh *msh)
{
	char	*cwd;

	cwd = ft_calloc(MAXPATHLEN, sizeof(char));
	getcwd(cwd, MAXPATHLEN);
	printf("%s\n", cwd);
	free(cwd);
	msh->exit_code = 0;
}
