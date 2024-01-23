/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:32:35 by edouard           #+#    #+#             */
/*   Updated: 2024/01/23 12:26:47 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_tab_free(map);
		return (NULL);
	}
	tilemap = tilemap_gen(map, game);
	ft_tab_free(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	game->background = new_panel(game, new_color(254, 254, 254, 0));
}

int start (t_game *game, int argc, char **argv)
{
    game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (1);
	game->og_collects = game->collects;
    	return (0);
}