/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:15:43 by elevast           #+#    #+#             */
/*   Updated: 2023/10/17 09:50:48 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	cdest = (char *)dest;
	csrc = (const char *)src;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

/*int main() {
    char source[] = "Hello, World!";
    char destination[20];

    memcpy(destination, source, sizeof(source));

    destination[sizeof(source) - 1] = '\0';

    printf("%s\n", destination); // Affiche "Hello, World!"

    return 0;
}*/
