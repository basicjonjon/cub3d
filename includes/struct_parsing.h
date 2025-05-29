/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/05/23 15:01:02 by jle-doua         ###   ########.fr       */
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

typedef struct s_data
{
	t_asset		asset;
	t_map		param;
	t_img		img;
	t_player	player;
	void		*mlx;
	void		*win;

}				t_data;

#endif