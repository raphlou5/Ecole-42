/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:59:12 by elevast           #+#    #+#             */
/*   Updated: 2023/10/18 11:34:41 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	f_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	j = 0;
	i = 0;
	tab = (char *)malloc((f_strlen(s1) + f_strlen(s2) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	return (tab);
}

/*int main()
{
	char *msg1 = "test du";
	char *msg2 = " code !";
	char *res = ft_strjoin(msg1, msg2);
	printf("le resultat est : %s", res);
	free(res);
	return (0);
}*/
