/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:28 by elevast           #+#    #+#             */
/*   Updated: 2024/03/26 14:28:07 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	convey;
	static int	letter;

	if (signal == SIGUSR1)
		letter += (1 << convey);
	convey++;
	if (convey == 8)
	{
		ft_printf("%c", letter);
		convey = 0;
		letter = 0;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	(void)av;
	if (ac > 1)
	{
		ft_printf("Error");
		exit(1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
