/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:07:36 by elevast           #+#    #+#             */
/*   Updated: 2023/10/19 11:16:41 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != '\0')
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}

/*char custom_function(unsigned int index, char c)
{
	return c + 1;
}

int main()
{
	const char *input = "Hello, World!";
	char *result = ft_strmapi(input, custom_function);
	if (result == NULL)
	{
		printf("Erreur d'allocation mémoire.\n");
		return 1;
	}
	printf("Chaîne d'entrée : %s\n", input);
	printf("Résultat après l'application de la fonction 
	personnalisée : %s\n", result);
	free(result);
	return 0;
}*/
