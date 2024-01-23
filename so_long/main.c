/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:33:19 by edouard           #+#    #+#             */
/*   Updated: 2024/01/23 13:13:08 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.window, 2, 0, input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}