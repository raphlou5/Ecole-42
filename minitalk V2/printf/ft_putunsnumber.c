/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:09 by elevast           #+#    #+#             */
/*   Updated: 2024/03/09 08:40:03 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int numbers)
{
	int	i;

	i = 0;
	if (numbers == 0)
		return (1);
	while (numbers != 0)
	{
		i++;
		numbers /= 10;
	}
	return (i);
}

int	ft_putunsnumber(unsigned int c)
{
	int	len;

	len = ft_len(c);
	if (c >= 10)
	{
		ft_putunsnumber(c / 10);
		ft_putunsnumber(c % 10);
	}
	else if (c < 10)
	{
		ft_putchar(c + '0');
	}
	return (len);
}
