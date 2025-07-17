/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:38:01 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/02 15:04:08 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_texture_null(t_texture *texture)
{
	texture->south.img_ptr = NULL;
	texture->east.img_ptr = NULL;
	texture->west.img_ptr = NULL;
	texture->north.img_ptr = NULL;
}



int	create_img(t_data *data, t_img *img, char *path, int *h)
{
	img->img_ptr = mlx_xpm_file_to_image(data->mlx, path, h, h);
	if (!img->img_ptr)
		return (1);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bit_per_pixels,
			&img->line_lenght, &img->endian);
	img->bit_per_pixels /= 8;
	return (0);
}

int	texture_init(t_data *data, t_asset *a)
{
	t_texture	t;
	int			h;
	init_texture_null(&t);
	create_img(data, &t.north, a->no_path, &h);
	create_img(data, &t.south, a->so_path, &h);
	create_img(data, &t.east, a->ea_path, &h);
	create_img(data, &t.west, a->we_path, &h);
	t.tex_h = h;
	t.tex_w = h;
	data->texture = t;
	return (0);
}
