/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:45:02 by elevast           #+#    #+#             */
/*   Updated: 2024/04/09 15:51:44 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_square(size_t y, size_t x, t_data *data)
{
	if (data->map_dup == NULL)
		return (false);
	if (data->map_dup[y][x] == '1')
		return (false);
	else if (data->map_dup[y][x] == 'C')
		data->c++;
	else if (data->map_dup[y][x] == 'E')
	{
		data->e = 1;
		return (false);
	}
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
