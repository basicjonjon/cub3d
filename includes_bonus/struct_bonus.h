/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/21 00:32:33 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "struct_utils.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bit_per_pixels;
	int		line_lenght;
	int		endian;
}			t_img;

typedef struct s_texture
{
	char	*path;
	t_img	img;
	int		tex_w;
	int		tex_h;
}			t_texture;

typedef struct s_asset
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_texture	door;
	t_texture	tfloor;
	t_texture	tceiling;
	int			ceiling;
	int			floor;
}				t_asset;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	rot_left;
	bool	rot_right;
	bool	map;
	bool	run;
	bool	interact;
	long	tt_interact;
}			t_player;

typedef struct s_map
{
	char	**map;
	int		map_x;
	int		map_y;
}				t_map;

typedef struct s_config
{
	int		block;
	int		player_size;
	int		map_w;
	int		map_h;
	float	fov;
	float	rot_speed;
	float	sensitivity;
	float	move_speed;
	float	run_speed;
	int		nbr_rays;
	float	column_width;
}				t_config;

typedef struct s_hud
{
	t_texture	batterie[6];
	t_texture	rec[2];
	t_texture	border[4];
	t_texture	center_cam;
	int			rec_position;
	int			rec_tempo;
	long		time_start;
	long		bat_tempo;
	int			bat_pos;
	int			save_bat_pos;
}				t_hud;

typedef struct s_data
{
	t_config	conf;
	t_asset		asset;
	t_hit		hit;
	t_map		param;
	t_player	player;
	t_img		img;
	t_hud		hud;
	void		*mlx;
	void		*win;
}				t_data;

#endif