/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:55:02 by elevast           #+#    #+#             */
/*   Updated: 2023/11/09 11:10:13 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*nbtochr(int n, int length, long int num)
{
	int		index;
	char	*str;

	index = length - 1;
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[index] = (num % 10) + '0';
		num /= 10;
		index--;
	}
	str[length] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			length;

	num = n;
	length = 0;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0)
		{
			length++;
			num = -num;
		}
		while (num > 0)
		{
			length++;
			num /= 10;
		}
	}
	num = n;
	return (nbtochr(n, length, num));
}

/*int main() {
    int num = 0;
    char *result = ft_itoa(num);

    if (result != NULL) {
        printf("Entier: %d\nChaîne: %s\n", num, result);
        free(result);
    } else {
        printf("Échec de l'allocation mémoire.\n");
    }

    return 0;
}*/
