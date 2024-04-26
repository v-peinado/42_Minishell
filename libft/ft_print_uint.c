/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:55 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/24 12:49:30 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_uint(unsigned int n, int *len)
{
	if (n > 9)
		ft_print_uint(n / 10, len);
	ft_print_char(n % 10 + '0', len);
}
