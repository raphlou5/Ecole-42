/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:52:03 by elevast           #+#    #+#             */
/*   Updated: 2024/03/07 10:26:21 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int ft_atoi(const char *str)
{
    int i;
    int sign;
    unsigned long int result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += str[i] - '0';
        i++;
    }
    return (result * sign);
}

void ft_send_bits(int pid, char i)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((i & (0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        bit++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0')
        {
            ft_send_bits(pid, argv[2][i]);
            i++;
        }
        // Ajout du caractère nul à la fin du message
        ft_send_bits(pid, '\0');
    }
    else
    {
        ft_printf("\033[91mError: wrong format.\033[0m\n");
        ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
        return (1);
    }
    return (0);
}
