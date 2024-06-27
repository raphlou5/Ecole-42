/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:36:58 by elevast           #+#    #+#             */
/*   Updated: 2024/06/26 16:41:09 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_write(t_info *info, int id, char *string)
{
	pthread_mutex_lock(&(info->writing));
	if (!(info->dieded))
	{
		printf("%lli ", timestamp() - info->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(info->writing));
	return ;
}
