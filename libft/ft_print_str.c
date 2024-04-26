/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:59:02 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/24 12:49:17 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		(*len) = (*len) + 6;
		return ;
	}
	while (str[i])
	{
		ft_print_char(str[i], len);
		i++;
	}
}
