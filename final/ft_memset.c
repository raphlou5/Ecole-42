/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:41:15 by elevast           #+#    #+#             */
/*   Updated: 2023/10/16 14:39:22 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

/*int main()
{
    int arr[5];
    size_t arr_len = sizeof(arr) / sizeof(arr[0]); // Cal taille tableau

    // Remplir le tableau avec la valeur 42
    ft_memset(arr, 42, sizeof(arr));

    // Afficher le contenu du tableau
    for (size_t i = 0; i < arr_len; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    return 0;
}*/
