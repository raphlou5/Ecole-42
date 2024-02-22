/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:23:44 by edouard           #+#    #+#             */
/*   Updated: 2024/02/22 15:23:45 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}
