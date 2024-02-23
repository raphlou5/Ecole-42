/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:43 by elevast           #+#    #+#             */
/*   Updated: 2024/02/23 11:30:04 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_size(char **map)
{
	int	size;

	size = 0;
	while (map[size] != NULL)
		size++;
	return (size);
}

char	**allocate_new_map_memory(int size)
{
	char	**new_map;

	new_map = (char **)malloc((size + 1) * sizeof(char *));
	return (new_map);
}

void	initialize_new_map(char **new_map, char **map, int size)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	while (i < size)
	{
		length = 0;
		while (map[i][length])
			length++;
		new_map[i] = (char *)malloc((length + 1) * sizeof(char));
		if (new_map[i] == NULL)
		{
			j = 0;
			while (j < i)
				free(new_map[j++]);
			free(new_map);
			return ;
		}
		j = 0;
		while (j <= length)
			new_map[i][j++] = '\0';
		i++;
	}
	new_map[size] = NULL;
}

char	**create_new_map(char **map)
{
	int		size;
	char	**new_map;

	size = get_map_size(map);
	new_map = allocate_new_map_memory(size);
	if (new_map == NULL)
		return (NULL);
	initialize_new_map(new_map, map, size);
	return (new_map);
}

void	copy_existing_map(char **map, char **new_map)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (map[size] != NULL)
		size++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}
