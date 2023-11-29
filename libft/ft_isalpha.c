/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:15:11 by elevast           #+#    #+#             */
/*   Updated: 2023/11/10 12:31:16 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_isalpha(int c)
{
	int	is_alpha;

	is_alpha = 1;
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
	{
		is_alpha = 0;
	}
	return (is_alpha);
}

/*int main() {
    char chaine1[] = "HelloWorld";
    char chaine2[] = "123abc";
    
    if (ft_isalpha(chaine1)) {
        printf("La chaine '%s' contient uniquement
         des lettres alphabétiques.\n", chaine1);
    } else {
        printf("La chaine '%s' ne contient pas 
        uniquement des lettres alphabétiques.\n", chaine1);
    }

    if (ft_isalpha(chaine2)) {
        printf("La chaine '%s' contient uniquement
         des lettres alphabétiques.\n", chaine2);
    } else {
        printf("La chaine '%s' ne contient pas 
        uniquement des lettres alphabétiques.\n", chaine2);
    }

    return 0;
}*/