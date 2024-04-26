/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:09:42 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:21 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int(int num, int *len)
{
	long long	n;

	n = num;
	if (n == 0)
	{
		write(1, "0", 1);
		(*len)++;
	}
	if (n < 0)
	{
		ft_print_char('-', len);
		n = n *(-1);
	}
	if (n > 0)
	{
		if (n > 9)
			ft_print_int(n / 10, len);
		ft_print_char(n % 10 + '0', len);
	}
}
