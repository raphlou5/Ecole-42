/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:23:12 by edouard           #+#    #+#             */
/*   Updated: 2024/03/05 14:37:06 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_charcpt(char *str, char chr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == chr)
			ret++;
		i++;
	}
	return (ret);
}

static int	ft_strnchr(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			return (i);
		i++;
	}
	return (i);
}

char	**empty_string(void)
{
	char	**ret;

	ret = (char **) malloc(sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[0] = NULL;
	return (ret);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		y;
	int		cpt;
	char	**ret;

	i = 0;
	y = 0;
	if (!str || *str == '\0')
		return (empty_string());
	ret = (char **)malloc(sizeof(char *) * (ft_charcpt(str, sep) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		cpt = ft_strnchr(&str[i], sep);
		ret[y] = ft_strncpy(&str[i], cpt);
		if (str[i + cpt] != '\0')
			i += (cpt + 1);
		else
			i += cpt;
		y++;
	}
	ret[y] = NULL;
	free(str);
	return (ret);
}
