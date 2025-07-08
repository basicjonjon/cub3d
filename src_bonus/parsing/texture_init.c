/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:38:01 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/08 17:22:15 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_init(t_data *data, t_asset *a)
{
	t_texture	t;
	int			w;
	int			h;

	t.north.img_ptr = mlx_xpm_file_to_image(data->mlx, a->no_path, &w, &h);
	if (!t.north.img_ptr)
		return (1);
	t.north.addr = mlx_get_data_addr(t.north.img_ptr,
										&t.north.bit_per_pixels,
										&t.north.line_lenght,
										&t.north.endian);
	t.south.img_ptr = mlx_xpm_file_to_image(data->mlx, a->so_path, &w, &h);
	if (!t.south.img_ptr)
		return (1);
	t.south.addr = mlx_get_data_addr(t.south.img_ptr,
										&t.south.bit_per_pixels,
										&t.south.line_lenght,
										&t.south.endian);
	t.east.img_ptr = mlx_xpm_file_to_image(data->mlx, a->ea_path, &w, &h);
	if (!t.east.img_ptr)
		return (1);
	t.east.addr = mlx_get_data_addr(t.east.img_ptr,
										&t.east.bit_per_pixels,
										&t.east.line_lenght,
										&t.east.endian);
	t.west.img_ptr = mlx_xpm_file_to_image(data->mlx, a->we_path, &w, &h);
	if (!t.west.img_ptr)
		return (1);
	t.west.addr = mlx_get_data_addr(t.west.img_ptr,
										&t.west.bit_per_pixels,
										&t.west.line_lenght,
										&t.west.endian);
	t.north.bit_per_pixels /= 8;
	t.south.bit_per_pixels /= 8;
	t.east.bit_per_pixels /= 8;
	t.west.bit_per_pixels /= 8;
	t.ceiling = rgb_to_int(*a->ceiling);
	t.floor = rgb_to_int(*a->floor);
	t.tex_h = h;
	t.tex_w = w;
	data->texture = t;
	return (0);
}
