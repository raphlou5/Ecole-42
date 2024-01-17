/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:43:33 by elevast           #+#    #+#             */
/*   Updated: 2023/11/29 10:53:49 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ch)
			return (ch);
	}
	return (0);
}

void	*ft_calloc(int nmemb, int size)
{
	int		total;
	int		i;
	char	*alloced;

	total = nmemb * size;
	i = 0;
	alloced = malloc(total);
	if (!alloced)
		return (NULL);
	while (total-- > 0)
		alloced[i++] = '\0';
	return ((void *)alloced);
}
