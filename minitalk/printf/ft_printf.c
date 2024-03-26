/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:09 by elevast           #+#    #+#             */
/*   Updated: 2024/03/09 08:39:40 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char symboll, va_list ptr)
{
	int	res;

	res = 0;
	if (symboll == 'c')
		res = res + ft_putchar(va_arg(ptr, int));
	else if (symboll == 'x')
		res = res + ft_printhex(va_arg(ptr, unsigned int), 'x');
	else if (symboll == 'X')
		res = res + ft_printhex(va_arg(ptr, unsigned int), 'X');
	else if (symboll == 'p')
		res = res + printthapointer(va_arg(ptr, unsigned long long), 'p');
	else if (symboll == 's')
		res = res + ft_printstr(va_arg(ptr, char *));
	else if (symboll == 'd' || symboll == 'i')
		res = res + ft_putnbr(va_arg(ptr, int));
	else if (symboll == 'u')
		res = res + ft_putunsnumber(va_arg(ptr, unsigned int));
	else if (symboll == '%')
	{
		res = res + ft_putchar('%');
	}
	else
		res = res + ft_putchar(symboll);
	return (res);
}

int	ft_printf(const char *symboll, ...)
{
	va_list	ptr;
	int		res;
	int		i;

	res = 0;
	i = 0;
	va_start(ptr, symboll);
	while (symboll[i])
	{
		if (symboll[i] == '%')
		{
			if (symboll[i + 1] == '\0')
				break ;
			res = res + ft_format(symboll[i + 1], ptr);
			i++;
		}
		else
			res = res + ft_putchar(symboll[i]);
		i++;
	}
	va_end(ptr);
	return (res);
}
