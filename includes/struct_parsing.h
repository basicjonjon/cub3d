/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/29 13:40:17 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSING_H
# define STRUCT_PARSING_H

typedef struct s_draw
{
	int		i;
	int		start;
	int		end;
	float	height;
}	t_draw;

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_dir;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bit_per_pixels;
	int			line_lenght;
	int			endian;
}				t_img;

typedef struct s_texture
{
	char		*path;
	t_img		img;
	int			tex_w;
	int			tex_h;
}				t_texture;

typedef struct s_asset
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	int			ceiling;
	int			floor;
}				t_asset;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	float		dirx;
	float		diry;
	float		plane_x;
	float		plane_y;
	bool		keyup;
	bool		keydown;
	bool		keyleft;
	bool		keyright;
	bool		rotleft;
	bool		rotright;
	bool		run;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			map_x;
	int			map_y;
}				t_map;

typedef struct s_ray
{
	float		pos_x;
	float		pos_y;
	int			map_x;
	int			map_y;
	float		raydirx;
	float		raydiry;
	float		deltadist_x;
	float		deltadist_y;
	int			step_x;
	int			step_y;
	float		sidedist_x;
	float		sidedist_y;
}				t_ray;

typedef struct s_hit_info
{
	t_dir		wall_dir;
	float		wall_hit_x;
	int			tex_x;
	int			tex_y;
}				t_hit;

typedef struct s_config
{
	int			player_size;
	int			map_w;
	int			map_h;
	float		fov;
	float		rot_speed;
	float		move_speed;
	float		run_speed;
	int			nbr_rays;
	float		column_width;
}				t_config;

typedef struct s_data
{
	t_config	conf;
	t_asset		asset;
	t_hit		hit;
	t_map		param;
	t_player	player;
	t_img		img;
	void		*mlx;
	void		*win;
}				t_data;

#endif