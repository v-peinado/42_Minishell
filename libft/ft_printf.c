/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:27:21 by vpeinado          #+#    #+#             */
/*   Updated: 2024/04/24 12:49:38 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

static void	ft_type(char ch, va_list *args, int *len)
{
	if (ch == 'c')
		ft_print_char(va_arg(*args, int), len);
	else if (ch == 's')
		ft_print_str(va_arg(*args, char *), len);
	else if (ch == 'p')
		ft_print_ptr(va_arg(*args, void *), len);
	else if (ch == 'd' || ch == 'i')
		ft_print_int(va_arg(*args, int), len);
	else if (ch == 'u')
		ft_print_uint(va_arg(*args, unsigned int), len);
	else if (ch == 'X' || ch == 'x')
		ft_print_hex(va_arg(*args, unsigned int), len, ch);
	else
	{
		if (ch == '\0')
			return ;
		write(1, &ch, 1);
		(*len)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i_str;
	int		total_len;

	va_start(args, format);
	i_str = 0;
	total_len = 0;
	while (format[i_str])
	{
		if (format[i_str] == '%')
		{
			i_str++;
			ft_type(format[i_str], &args, &total_len);
			i_str++;
		}
		else
		{
			ft_print_char(format[i_str], &total_len);
			i_str++;
		}
	}
	va_end(args);
	return (total_len);
}
/*
int	main(void)
{
	//int chr = 'A';
	//char *str = "HOLA";
	//int nbr = 1;
	//unsigned int usg = 42;
	//void *ptr = "hola";
	
	//printf("ORIGINAL:\nCaracter: %c\nString: %s\n
	//Porcentaje: %r\nEntero: %d\nUnsigned: %u\n", chr, str, nbr, usg);
	//ft_printf("FUNCION 42:\nCaracter: %c\nString: %s\n
	//Porcentaje: %r\nEntero: %d\nUnsigned: %u\n", chr, str, nbr, usg);
	//int ret2 = printf(" NULL %s NULL ", NULL);
	//int ret1 = ft_printf(" NULL %s NULL ", NULL);
	
	printf(" %p %p ", NULL, NULL);
	//ft_printf("%p", ptr);	
}*/
