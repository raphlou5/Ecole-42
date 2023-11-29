/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:19:26 by elevast           #+#    #+#             */
/*   Updated: 2023/11/09 11:08:46 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*tab;
	int		i;
	int		j;
	int		lens1;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	lens1 = ft_strlen(s1);
	while (lens1 > i && is_in_set(s1[lens1 - 1], set))
		lens1--;
	if (i >= lens1)
		return (ft_strdup(""));
	tab = (char *)malloc((lens1 - i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	j = 0;
	while (i < lens1)
		tab[j++] = s1[i++];
	tab[j] = '\0';
	return (tab);
}

/*int main()
{
	char *msg = "detit message P";
	char *cond = "P";
	char *res = ft_strtrim(msg, cond);

	if (res)
	{
		printf("Le resultat est : %s\n", res);
		free(res);
	}
	else
	{
		printf("Erreur d'allocation mémoire.\n");
	}
	return (0);
}*/
