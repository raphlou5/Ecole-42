/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:52:03 by elevast           #+#    #+#             */
/*   Updated: 2024/03/26 14:12:30 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
	}
	return (res * sign);
}

void	ft_send(int pid, char letter)
{
	int	convey;

	convey = 0;
	while (convey < 8)
	{
		if ((letter & (1 << convey)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		convey++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*current_char;

	if (argc != 3)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		exit(1);
	}
	else
	{
		current_char = &argv[2][0];
		check_the_end(&argv[1][0]);
		pid = ft_atoi(argv[1]);
		check_pid(pid);
		check_the_message(&argv[2][0]);
		while (*current_char != '\0')
		{
			ft_send(pid, *current_char);
			current_char++;
		}
		ft_send(pid, '\n');
	}
}
