/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/28 15:49:05 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSING_BONUS_H
# define STRUCT_PARSING_BONUS_H

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				s_dir;

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

	float		dirX;
	float		dirY;
	float		planeX;
	float		planeY;

	bool		keyUp;
	bool		keyDown;
	bool		keyLeft;
	bool		keyRight;

	bool		rotLeft;
	bool		rotRight;

	bool		map;

	bool		run;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			mapX;
	int			mapY;
}				t_map;

typedef struct s_ray
{
	float		posX;
	float		posY;

	int			mapX;
	int			mapY;

	float		rayDirX;
	float		rayDirY;

	float		deltaDistX;
	float		deltaDistY;

	int			stepX;
	int			stepY;
	float		sideDistX;
	float		sideDistY;
}				t_ray;

typedef struct s_hit_info
{
	s_dir		wall_dir;
	float		wall_hit_x;
	int			tex_x;
	int			tex_y;
}				t_hit;

typedef struct s_config
{
	int			block;
	int			player_size;
	int			mapW;
	int			mapH;
	float		fov;
	float		rot_speed;
	float		sensitivity;
	float		move_speed;
	float		run_speed;
	int			nbr_rays;
	float		column_width;
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