/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:04:09 by elevast           #+#    #+#             */
/*   Updated: 2024/03/09 08:39:46 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *symboll, ...);
int	ft_printhex(unsigned int c, char format);
int	printthapointer(unsigned long long c, char format);
int	ft_putchar(int c);
int	ft_putnbr(int c);
int	ft_printstr(char *s);
int	ft_putunsnumber(unsigned int c);

#endif
