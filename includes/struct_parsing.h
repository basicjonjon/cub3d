/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/03 15:52:57 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_PARSING_H
# define STRUCT_PARSING_H

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

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
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	int			tex_w;
	int			tex_h;
	int			ceiling;
	int			floor;
}				t_texture;

typedef struct s_asset
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_color		*ceiling;
	t_color		*floor;
}				t_asset;

typedef struct s_player
{
	float		x;
	float		y;
	float		posX;
	float		posY;
	float		angle;

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
	int			exist;
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
	float		move_speed;
	float		run_speed;
	int			nbr_rays;
	float		column_width;
}				t_config;

////////////////////////////////////////////////////////////
// BONUS
////////////////////////////////////////////////////////////

typedef struct s_hud
{
	// void *border;
	// void *rec[2];
	t_img batterie;
	// void *mod[2];
}	t_hud;

////////////////////////////////////////////////////////////
// BONUS
////////////////////////////////////////////////////////////

typedef struct s_data
{
	t_config	conf;
	t_asset		asset;
	t_texture	texture;
	t_hit		hit;
	t_map		param;
	t_player	player;
	t_img		img;
	t_hud		hud;
	void		*mlx;
	void		*win;

}				t_data;

#endif