/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/05 16:55:03 by mmarpaul         ###   ########.fr       */
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
	int			x;
	int			y;
	double		posX;
	double		posY;
	double		angle;

	bool		keyUp;
	bool		keyDown;
	bool		keyLeft;
	bool		keyRight;

	bool		rotLeft;
	bool		rotRight;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			mapX;
	int			mapY;
}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bit_per_pixels;
	int			line_lenght;
	int			endian;
}				t_img;

typedef struct s_config
{
	int		block;
	int		player_size;
	int		mapX;
	int		mapY;
	double	fov;
	double	rot_speed;
	double	move_speed;
}			t_config;

typedef struct s_data
{
	t_config	conf;
	t_asset		asset;
	t_map		param;
	t_player	player;
	t_img		img;
	void		*mlx;
	void		*win;

}				t_data;

#endif