/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:36:32 by elevast           #+#    #+#             */
/*   Updated: 2023/10/18 14:53:42 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*actualtotemp(char const *s, int i, int j)
{
	int		p;
	char	*tabtemp;

	tabtemp = (char *)malloc((j + 1) * sizeof(char));
	p = 0;
	while (p < j)
	{
		tabtemp[p] = s[i - j + p];
		p++;
	}
	tabtemp[p] = '\0';
	return (tabtemp);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		compteur;
	char	**result;

	j = 0;
	i = 0;
	compteur = 0;
	result = (char **)malloc((ft_strlen((char *)s) + 1) * sizeof(char *));
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (j > 0)
				result[compteur++] = actualtotemp(s, i, j);
			j = 0;
		}
		else
			j++;
		i++;
	}
	result[compteur] = NULL;
	return (result);
}

/*int main()
{
    const char *s = "Je suis un message";
    char c = 'u';
    char **res = ft_split(s, c);

    if (res)
    {
        int i = 0;
        while (res[i])
        {
            printf("Le resultat est : %s\n", res[i]);
            free(res[i]);
            i++;
        }
        free(res);
    }

    return 0;
}*/
