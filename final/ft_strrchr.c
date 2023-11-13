/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:31:02 by elevast           #+#    #+#             */
/*   Updated: 2023/11/10 12:29:31 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string) - 1;
	while (i >= 0)
	{
		if ((unsigned char)string[i] == (unsigned char)searchedChar)
		{
			return ((char *)(string + i));
		}
		i--;
	}
	if (searchedChar == '\0')
	{
		return ((char *)(string + ft_strlen(string)));
	}
	return (NULL);
}

/*int main()
{
    const char *text = "Exemple de texte";
    char search = 'd';

    char *result = strrchr(text, search);

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
