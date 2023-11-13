/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:51:10 by elevast           #+#    #+#             */
/*   Updated: 2023/11/10 10:41:20 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t h;
	size_t n;

	h = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[h] != '\0')
	{
		n = 0;
		while (big[h + n] == little[n] && (h + n) < len)
		{
			if (big[h + n] == '\0' && little[n] == '\0')
				return ((char *)&big[h]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + h);
		h++;
	}
	return (0);
}

/*int main()
{
    const char *big = "This is a test string for testing my_strnstr function.";
    const char *little = "test";
    size_t len = strlen(big);

    char *result = strnstr(big, little, len);

    if (result != NULL)
    {
        printf("Substring found: %s\n", result);
    }
    else
    {
        printf("Substring not found.\n");
    }

    return 0;
}*/
