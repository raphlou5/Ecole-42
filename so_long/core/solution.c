/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:39:33 by edouard           #+#    #+#             */
/*   Updated: 2024/02/23 11:29:12 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_map(char **map, t_data *data)
{
	char	**new_map;

	new_map = create_new_map(map);
	if (new_map == NULL)
		return ;
	copy_existing_map(map, new_map);
	data->map_dup = new_map;
}

void	ft_player_pos(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map_dup[i])
	{
		while (data->map_dup[i][y])
		{
			if (data->map_dup[i][y] == data->content.player)
			{
				data->player_pos.x = i;
				data->player_pos.y = y;
				return ;
			}
			y++;
		}
		y = 0;
		i++;
	}
}

void	ft_count_collectibles(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map_dup[i])
	{
		while (data->map_dup[i][y])
		{
			if (data->map_dup[i][y] == data->content.collect)
				data->total_collectibles++;
			y++;
		}
		y = 0;
		i++;
	}
}

int	valid_path(t_data *data, int x, int y)
{
	static int	e;
	static int	c;

	if (x < 0 || y < 0 || x > data->width || y > data->height
		|| data->map_dup[y][x] == '1' || data->map_dup[y][x] == 'X')
		return (0);
	if (data->map_dup[y][x] == 'E')
	{
		e++;
		data->map_dup[y][x] = 'X';
		return (0);
	}
	if (data->map_dup[y][x] == 'C')
		c++;
	data->map_dup[y][x] = 'X';
	valid_path(data, x + 1, y);
	valid_path(data, x - 1, y);
	valid_path(data, x, y + 1);
	valid_path(data, x, y - 1);
	if (e == 1 && c == data->total_collectibles)
		return (true);
	else
		return (false);
}

int	valid_path_core(t_data *data)
{
	copy_map(data->map, data);
	ft_player_pos(data);
	ft_count_collectibles(data);
	return (valid_path(data, data->player_pos.x, data->player_pos.y));
}
