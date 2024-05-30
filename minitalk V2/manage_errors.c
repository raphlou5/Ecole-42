/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:19:46 by elevast           #+#    #+#             */
/*   Updated: 2024/03/08 10:19:50 by elevast          ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}

void	check_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf("\033[91mNO valid PID.\033[0m\n");
		exit(1);
	}
	if (kill(pid, 0) != 0)
	{
		ft_printf("\033[41mWrong PID\033[0m\n");
		exit(1);
	}
}

void	check_the_end(char *str)
{
	int	isit;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		isit = ft_isdigit(str[i]);
		if (isit == 0)
		{
			ft_printf("\033[91mNO valid PID.\033[0m\n");
			exit(1);
		}
		i++;
	}
}

void	check_the_message(char *str)
{
	if (ft_strlen(str) == 0)
		exit(1);
}
