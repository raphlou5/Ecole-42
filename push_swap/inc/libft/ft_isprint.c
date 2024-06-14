/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:27:28 by elevast           #+#    #+#             */
/*   Updated: 2023/11/10 12:31:33 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_isprint(int c)
{
	int	is_printable;

	is_printable = 1;
	if (!(c >= ' ' && c <= '~'))
	{
		is_printable = 0;
	}
	return (is_printable);
}
