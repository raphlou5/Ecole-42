/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:26:55 by elevast           #+#    #+#             */
/*   Updated: 2024/01/23 12:26:33 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "../so_long.h"
#include "../gnl/get_next_line.h"
#include "../Lib/libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}				t_mapcheckerdata;

int	valid_char(char c);
char	**read_map(char *file);
int	valid_uniquechar(char c, char checker, t_bool *player);
int	valid_border(char c, t_vector point, t_vector size);
int	ft_linecount(char **table);
t_tile	**tilemap_gen(char **map, t_game *game);

#endif