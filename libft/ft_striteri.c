/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:17:17 by elevast           #+#    #+#             */
/*   Updated: 2023/10/19 11:27:23 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void print_char_with_index(unsigned int index, char *c)
{
	printf("Caractère à l'indice %u : %c\n", index, *c);
}

int main()
{
	char input[] = "Hello, World!";
	printf("Chaîne d'entrée : %s\n", input);
	ft_striteri(input, print_char_with_index);
	return (0);
}*/
