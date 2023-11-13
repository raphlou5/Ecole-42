/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:43:08 by elevast           #+#    #+#             */
/*   Updated: 2023/08/22 09:33:33 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copie;

	copie = (char *)malloc(len(src) + 1);
	i = 0;
	while (src[i])
	{
		copie[i] = src[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}

/*int	main (void)
{
    char *original = "Hello, world!";
    char *copie = ft_strdup(original);

    printf("Original: %s\n", original);
    printf("copie: %s\n", copie);
	free(copie);
	return 0;
}*/
