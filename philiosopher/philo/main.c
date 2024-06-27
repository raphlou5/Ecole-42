/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:36:50 by elevast           #+#    #+#             */
/*   Updated: 2024/06/26 16:44:32 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	if (argc != 5 && argc != 6)
	{
		printf("mauvais nombres d'arguments");
		return (0);
	}
	ret = init_all(&info, argv);
	if (ret)
	{
		printf("error");
		return (0);
	}
	if (philo(&info))
	{
		printf("erreur creation thread");
		return (0);
	}
	return (0);
}
