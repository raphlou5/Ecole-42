/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:39:33 by edouard           #+#    #+#             */
/*   Updated: 2024/04/08 11:47:12 by edouard          ###   ########.fr       */
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
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.player)
			{
				data->player_pos_x = i;
				data->player_pos_y = y;
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
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.collect)
				data->total_collectibles++;
			y++;
		}
		y = 0;
		i++;
	}
}


void free_map_dup(t_data *data)
{
    char **map_dup = data->map_dup;
    int i;
    for (i = 0; map_dup[i]; i++)
        free(map_dup[i]);
    free(map_dup);
}

static bool	check_square(size_t y, size_t x, t_data *data)
{
	if (data->map_dup == NULL)
		return false;
	if (data->map_dup[y][x] == '1')
		return (false);
	else if (data->map_dup[y][x] == 'C')
		data->c++;
	else if (data->map_dup[y][x] == 'E')
		data->e = 1;
	return (true);
}

static void	search_all_directions(size_t y, size_t x, t_data *data)
{
	if (!check_square(y, x, data))
		return ;
	else
		data->map_dup[y][x] = '1';
	search_all_directions(y, x + 1, data);
	search_all_directions(y, x - 1, data);
	search_all_directions(y + 1, x, data);
	search_all_directions(y - 1, x, data);
}

int	check_if_playable(t_data *data)
{
	search_all_directions(data->player_pos_y, data->player_pos_x, data);
	if (data->e == 0 || data->c != data->total_collectibles)
		{
			free_map_dup(data);
			return (0);
		}
	else
	{
		free_map_dup(data);
		return (1);
	}
}

int	valid_path_core(t_data *data)
{
	data->total_collectibles = 0;
	data->map_dup = NULL;
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->c = 0;
	data->e = 0;
	copy_map(data->map, data);
	ft_player_pos(data);
	ft_count_collectibles(data);
	if (check_if_playable(data) == 0)
		return(0);
	else
		return (1);
}