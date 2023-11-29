/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:12 by elevast           #+#    #+#             */
/*   Updated: 2023/11/29 13:57:55 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_unsigned_putnbr(unsigned int nb);
int	printadress(const unsigned long n);
int	ft_putpointer(void *adress);
int	ft_puthexalower(long double nbr);
int	ft_puthexaupper(long double nbr);

#endif