/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:53:57 by elevast           #+#    #+#             */
/*   Updated: 2023/11/29 13:56:18 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printadress(const unsigned long n)
{
	if (n / 16)
		return (printadress(n / 16) + printadress(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'a');
	return (1);
}

int	ft_putpointer(void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + printadress((unsigned long) adress));
}

int	ft_puthexalower(long double nbr)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= 16)
		count += ft_puthexalower(((unsigned long) nbr / 16));
	ft_putchar(hexa[(unsigned long)nbr % 16]);
	count++;
	return (count);
}

int	ft_puthexaupper(long double nbr)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= 16)
		count += ft_puthexaupper(((unsigned long) nbr / 16));
	ft_putchar(hexa[(unsigned long)nbr % 16]);
	count++;
	return (count);
}
