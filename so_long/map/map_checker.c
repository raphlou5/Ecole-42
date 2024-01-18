/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:26:59 by elevast           #+#    #+#             */
/*   Updated: 2024/01/18 14:03:25 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool valid_name (char *file)
{
    size_t length = ft_strlen(file);
    const char* extension = ".bar";
    size_t extensionLength = ft_strlen(extension);

    if (length < extensionLength)
        return false;
    return (ft_strcmp(file + length - extensionLength, extension) == 0);
}

static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

int tile_check (char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
		return (error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}


int map_checker (char **map)
{
	t_mapcheckerdata	data;
	int	                res;

    data = init_checkerdata(map);
    res = 1;
    
    while (map[data.point.y])
    {
        if(ft_strlen(map[data.point.y]) != map[data.size.x])
            {
                printf("Map not triangular");
                res = 0;
            }
        data.point.x = 0;
        while(map[data.point.y][data.point.x])
        {
            if(tile_check(map, &data) == FALSE)
                res = 0;
            data.point.x++;
        }
        data.point.y++;
    }
    if (!data.b_player || !data.b_exit || !data.b_collect)
    {
		printf("there must be one 'P' and 'E', and at least one 'C'");
        res = 0;
    }
    return(res);
}