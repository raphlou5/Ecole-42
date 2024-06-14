/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:54:51 by elevast           #+#    #+#             */
/*   Updated: 2023/11/10 12:32:29 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dest == src)
		return (dest);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i -1] = ((char *)src)[i -1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*int main() {
    char source[] = "Hello, world!";
    char destination[20];

    memmove(destination, source, 13);
    
    printf("Destination: %s\n", destination);

    return (0);
}*/
