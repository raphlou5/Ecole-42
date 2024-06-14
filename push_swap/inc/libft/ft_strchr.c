/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:45:58 by elevast           #+#    #+#             */
/*   Updated: 2023/11/10 12:29:01 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*int main()
{
    const char *text = "Exemple de texte";
    char search = 'd';

    char *result = strchr(text, search);

    if (result != NULL)
    {
        printf("Caractère trouvé : %c\n", *result);
    }
    else
    {
        printf("Caractère non trouvé.\n");
    }

    return 0;
}*/
