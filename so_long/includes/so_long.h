/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevast <elevast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:21:30 by edouard           #+#    #+#             */
/*   Updated: 2024/04/04 14:16:51 by elevast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	char	**map_dup;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	t_pos	player_pos;
	int		count;
	int		total_collectibles;
	int		e;
	int		c;
	int		player_pos_x;
	int		player_pos_y;
}				t_data;

int		ft_strchr(char *str, char *cmp);
void	*ft_error(char *str);
void	*ft_error_free(char *str, t_data *data);
void	*ft_free_map(t_data *data);
void	free_map_dup(t_data *data);
int		ft_same_char(char *str);

int		ft_same_char(char *str);
char	*get_map(int fd);
char	**map_core(char **str, t_data *data);
int		chk_map(char **argv);

int		ft_check_col(char *map_line, char col, t_data *data);
int		ft_check_line(char *map_line, char wall);
int		ft_check_other(char *map_line, t_cnt *content);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);
int		chk_collect(t_data *data);

void	set_img(t_data *data);
void	set_content(t_cnt *content);

void	core_render(t_data *data);
int		render(t_data *data);
void	render_other(t_data *data);
void	render_background(t_data *data);
void	render_down(t_data *data);
void	render_left(t_data *data);
void	render_right(t_data *data);
void	render_top(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

int		key_press(int keysym, t_data *data);
int		chk_collect(t_data *data);
int		end(t_data *data);

int		valid_path_core(t_data *data);
char	**create_new_map(char **map);
void	copy_existing_map(char **map, char **new_map);
int		check_if_playable(t_data *data);

#endif
