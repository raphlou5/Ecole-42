/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:19:12 by edouard           #+#    #+#             */
/*   Updated: 2024/04/09 11:35:23 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_same_char(char *str)
{
	int		i;
	char	buff;

	i = 0;
	buff = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buff && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	*ft_error_free(char *str, t_data *data)
{
	ft_free_map(data);
	write(2, str, ft_strlen(str));
	return (0);
}
