/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:14:13 by elevast           #+#    #+#             */
/*   Updated: 2024/05/30 10:48:56 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_processing = 0;

void	hdl_compl_msg(char **message, size_t *message_size, size_t *byte_count)
{
	write(STDOUT_FILENO, *message, *byte_count - 1);
	write(STDOUT_FILENO, "\n", 1);
	free(*message);
	*message = NULL;
	*message_size = 0;
	*byte_count = 0;
}

int	resize_message_buffer(char **message, size_t *message_size)
{
	*message_size += 1024;
	*message = realloc(*message, *message_size);
	if (!*message)
	{
		ft_printf("Failed to allocate memory");
		return (0);
	}
	return (1);
}

void	p_c(char **msg, size_t *msg_size, size_t *byte_count, char current_char)
{
	if (*byte_count >= *msg_size)
	{
		if (!resize_message_buffer(msg, msg_size))
			exit(EXIT_FAILURE);
	}
	(*msg)[(*byte_count)++] = current_char;
	if (current_char == '\0')
	{
		hdl_compl_msg(msg, msg_size, byte_count);
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		*message = NULL;
	static size_t	message_size = 0;
	static size_t	byte_count = 0;
	static int		bit_count = 0;
	static char		current_char = 0;

	(void)context;
	if (g_processing)
		return ;
	if (sig == SIGUSR1)
	{
		current_char |= (1 << bit_count);
	}
	bit_count++;
	if (bit_count == 8)
	{
		p_c(&message, &message_size, &byte_count, current_char);
		current_char = 0;
		bit_count = 0;
	}
	g_processing = 1;
	kill(info->si_pid, SIGUSR2);
	usleep(1000);
	g_processing = 0;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
