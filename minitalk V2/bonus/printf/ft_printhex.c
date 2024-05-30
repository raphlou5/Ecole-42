/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:55:07 by elevast           #+#    #+#             */
/*   Updated: 2024/03/09 08:55:10 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexalentgh(unsigned int c)
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

int	ft_printhex(unsigned int c, char format)
{
	int		i;
	int		lenghofhexa;
	char	*str;

	i = 0;
	lenghofhexa = hexalentgh(c);
	if (c >= 16)
	{
		ft_printhex(c / 16, format);
		ft_printhex(c % 16, format);
	}
	if (format == 'x')
		str = "0123456789abcdef";
	else if (format == 'X')
		str = "0123456789ABCDEF";
	if (c < 16)
	{
		if (format)
			ft_putchar(str[c]);
	}
	return (lenghofhexa);
}
