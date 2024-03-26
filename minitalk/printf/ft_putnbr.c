/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:09 by elevast           #+#    #+#             */
/*   Updated: 2024/03/09 08:40:01 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int numbers)
{
	int	i;

	i = 0;
	if (numbers <= 0)
	{
		i++;
		numbers *= -1;
	}
	while (numbers != 0)
	{
		i++;
		numbers /= 10;
	}
	return (i);
}

int	ft_putnbr(int c)
{
	int	len;

	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	len = ft_len(c);
	if (c < 0)
	{
		ft_putchar('-');
		c = c * -1;
	}
	if (c >= 10)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else if (c < 10)
	{
		ft_putchar(c + '0');
	}
	return (len);
}
