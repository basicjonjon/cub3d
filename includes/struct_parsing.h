/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:31:47 by jle-doua          #+#    #+#             */
/*   Updated: 2025/05/21 17:22:03 by jle-doua         ###   ########.fr       */
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

typedef struct s_texture
{
	void		*no_wall;
	void		*so_wall;
	void		*we_wall;
	void		*ea_wall;
	int			size;
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
	double		posX;
	double		posY;
	double		orient;

}				t_player;

typedef struct s_data
{
	t_texture	*texture;
	t_asset		*asset;
	t_player	*player;
	void		*mlx;
	void		*win;
	char		**map;
	int			mapX;
	int			mapY;
}				t_data;

#endif