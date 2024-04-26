/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:43:58 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:31 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void	ft_putptr(unsigned long long ptr, int *len)
{
	char			*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
		ft_putptr(ptr / 16, len);
	ft_print_char(hex[ptr % 16], len);
}

void	ft_print_ptr(void *ptr, int *len)
{
	unsigned long long	n;

	n = (unsigned long long)ptr;
	if (!ptr)
	{
		write(1, "0x0", 3);
		(*len) = (*len) + 3;
		return ;
	}
	write(1, "0x", 2);
	(*len) = (*len) + 2;
	ft_putptr(n, len);
}
