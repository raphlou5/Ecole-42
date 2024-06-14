/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:35:22 by elevast           #+#    #+#             */
/*   Updated: 2023/10/17 14:50:29 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = pointer1;
	p2 = pointer2;
	i = 0;
	while (i < size)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

/*int main()
{
    unsigned char buffer1[] = "Hello";
    unsigned char buffer2[] = "Hellx";
    size_t size = 5;

    int result = memcmp(buffer1, buffer2, size);

    if (result == 0)
    {
        printf("Les tableaux sont identiques.\n");
    }
    else if (result < 0)
    {
        printf("Le premier tableau est inférieur au deuxième.\n");
    }
    else
    {
        printf("Le premier tableau est supérieur au deuxième.\n");
    }

    return 0;
}*/
