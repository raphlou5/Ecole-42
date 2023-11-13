/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:15:43 by elevast           #+#    #+#             */
/*   Updated: 2023/10/17 12:47:04 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*int main() {
    char str[] = "Hello, World!";
    int target = 'o';

    void *result = ft_memchr(str, target, sizeof(str));

    if (result != NULL) {
        printf("L'octet 0x%x a été trouvé à la 
		position %ld.\n", target, (char *)result - str);
    } else {
        printf("L'octet 0x%x n'a pas été 
		trouvé dans la chaîne.\n", target);
    }

    return 0;
}*/
