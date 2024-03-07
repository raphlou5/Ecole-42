/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:28 by elevast           #+#    #+#             */
/*   Updated: 2024/03/07 10:22:43 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h> // Pour utiliser malloc et free
#include <unistd.h> // Pour utiliser usleep

#define TIMEOUT_DELAY 5000 // Microsecondes (ajustez selon vos besoins)

char *g_buffer = NULL; // Déclaration du tableau de caractères global
int g_index = 0; // Indice courant dans le tableau de caractères

void ft_handler(int signal)
{
    static int bit;
    static int i;

    if (signal == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        g_buffer = realloc(g_buffer, (g_index + 1) * sizeof(char)); // Allouer de la mémoire pour un caractère supplémentaire
        if (g_buffer == NULL)
        {
            ft_printf("Error: Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        g_buffer[g_index++] = i; // Ajouter le caractère au tableau
        bit = 0;
        i = 0;
    }
}

void print_buffer() // Fonction pour imprimer le contenu du tableau de caractères
{
    int j = 0;
    while (j < g_index)
    {
        ft_printf("%c", g_buffer[j]);
        j++;
    }
    ft_printf("\n");
    free(g_buffer); // Libérer la mémoire allouée pour le tableau
    g_buffer = NULL; // Réinitialiser le pointeur
    g_index = 0; // Réinitialiser l'indice du tableau
}

int main(int argc, char **argv)
{
    int pid;

    (void)argv;
    if (argc != 1)
    {
        ft_printf("\033[91mError: wrong format.\033[0m\n");
        ft_printf("\033[33mTry: ./server\033[0m\n");
        return (0);
    }
    pid = getpid();
    ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
    ft_printf("\033[90mWaiting for a message...\033[0m\n");
    while (argc == 1)
    {
        signal(SIGUSR1, ft_handler);
        signal(SIGUSR2, ft_handler);
        usleep(TIMEOUT_DELAY); // Attendre un court laps de temps
        if (g_index > 0 && g_buffer[g_index - 1] == '\0') // Si un caractère de fin de message est reçu
        {
            print_buffer(); // Imprimer le contenu du tableau
        }
    }
    return (0);
}
