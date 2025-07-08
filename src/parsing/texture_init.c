/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:38:01 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/08 19:25:52 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_init(t_data *data, t_asset *a)
{
	// int			w;
	// int			h;

	a->north.img.img_ptr = mlx_xpm_file_to_image(data->mlx, a->no_path, &a->north.tex_w, &a->north.tex_h);
	if (!a->north.img.img_ptr)
		return (1);
	a->north.img.addr = mlx_get_data_addr(a->north.img.img_ptr,
										&a->north.img.bit_per_pixels,
										&a->north.img.line_lenght,
										&a->north.img.endian);
	a->south.img.img_ptr = mlx_xpm_file_to_image(data->mlx, a->so_path, &a->south.tex_w, &a->south.tex_h);
	if (!a->south.img.img_ptr)
		return (1);
	a->south.img.addr = mlx_get_data_addr(a->south.img.img_ptr,
										&a->south.img.bit_per_pixels,
										&a->south.img.line_lenght,
										&a->south.img.endian);
	a->east.img.img_ptr = mlx_xpm_file_to_image(data->mlx, a->ea_path, &a->east.tex_w, &a->east.tex_h);
	if (!a->east.img.img_ptr)
		return (1);
	a->east.img.addr = mlx_get_data_addr(a->east.img.img_ptr,
										&a->east.img.bit_per_pixels,
										&a->east.img.line_lenght,
										&a->east.img.endian);
	a->west.img.img_ptr = mlx_xpm_file_to_image(data->mlx, a->we_path, &a->west.tex_w, &a->west.tex_h);
	if (!a->west.img.img_ptr)
		return (1);
	a->west.img.addr = mlx_get_data_addr(a->west.img.img_ptr,
										&a->west.img.bit_per_pixels,
										&a->west.img.line_lenght,
										&a->west.img.endian);
	a->north.img.bit_per_pixels /= 8;
	a->south.img.bit_per_pixels /= 8;
	a->east.img.bit_per_pixels /= 8;
	a->west.img.bit_per_pixels /= 8;
	// a->ceiling = rgb_to_int(*a->ceiling);
	// a->floor = rgb_to_int(*a->floor);
	return (0);
}
