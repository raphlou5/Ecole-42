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

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if ((unsigned char)string[i] == (unsigned char)searchedChar)
		{
			return ((char *)(string + i));
		}
		i++;
	}
	if (searchedChar == '\0')
	{
    		return ((char *)(string + i));
	}
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
