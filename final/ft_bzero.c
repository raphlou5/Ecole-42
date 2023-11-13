/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:45:54 by elevast           #+#    #+#             */
/*   Updated: 2023/10/16 16:03:40 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned long	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*int main() {
    unsigned char buffer[10];
    size_t len = sizeof(buffer);

    ft_bzero(buffer, len);

    printf("Après ft_bzero:\n");
    for (size_t i = 0; i < len; i++) {
        printf("buffer[%zu] = 0x%02X\n", i, buffer[i]);
    }

    return 0;
}*/
