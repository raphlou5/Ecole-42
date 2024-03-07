/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:09 by elevast           #+#    #+#             */
/*   Updated: 2023/11/29 13:56:17 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv(char form, va_list args)
{
	int	result;

	result = 0;
	if (form == 'c')
		result = ft_putchar((char) va_arg(args, int));
	else if (form == 's')
		result = ft_putstr(va_arg(args, char *));
	else if (form == 'p')
		result = ft_putpointer(va_arg(args, void *));
	else if (form == 'd')
		result = ft_putnbr(va_arg(args, int));
	else if (form == 'i')
		result = ft_putnbr(va_arg(args, int));
	else if (form == 'u')
		result = ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (form == 'x')
		result = ft_puthexalower(va_arg(args, unsigned int));
	else if (form == 'X')
		result = ft_puthexaupper(va_arg(args, unsigned ));
	else if (form == '%')
		result = ft_putchar('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
	{
		return (0);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len = len + conv(format[i + 1], args);
			i++;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
