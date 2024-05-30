/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:14:01 by elevast           #+#    #+#             */
/*   Updated: 2024/05/30 16:17:39 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_bit(int pid, int bit_val)
{
	if (bit_val)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_string(int pid, const char *message)
{
	size_t	i;
	int		bit;
	char	c;
	int		bit_val;

	i = 0;
	while (i <= ft_strlen(message))
	{
		c = message[i];
		bit = 0;
		while (bit < 8)
		{
			bit_val = (c >> bit) & 1;
			g_ack_received = 0;
			while (!g_ack_received)
			{
				send_bit(pid, bit_val);
				usleep(100);
			}
			bit++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	const char			*message = argv[2];
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n PID > 0\n", argv[0]);
		return (1);
	}
	check_the_end(&argv[1][0]);
	pid = ft_atoi(argv[1]);
	check_pid(pid);
	check_the_message(&argv[2][0]);
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	send_string(pid, message);
	return (0);
}
