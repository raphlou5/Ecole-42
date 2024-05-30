/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:09 by elevast           #+#    #+#             */
/*   Updated: 2024/03/09 08:39:56 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	poinlen(unsigned long long c)
{
	int	size;

	size = 0;
	if (c == 0)
		size++;
	while (c != 0)
	{
		size++;
		c = c / 16;
	}
	return (size);
}

static int	ft_printpointer(unsigned long long c, char format)
{
	int		i;
	int		lenghofhexa;
	char	*str;

	i = 0;
	lenghofhexa = poinlen(c);
	if (c >= 16)
	{
		ft_printpointer(c / 16, format);
		ft_printpointer(c % 16, format);
	}
	if (format == 'p')
		str = "0123456789abcdef";
	if (c < 16)
	{
		if (format)
			ft_putchar(str[c]);
	}
	return (lenghofhexa + 2);
}

int	printthapointer(unsigned long long c, char format)
{
	write(1, "0x", 2);
	return (ft_printpointer(c, format));
}
