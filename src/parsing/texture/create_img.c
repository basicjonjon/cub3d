/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:41:54 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/22 13:42:38 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_img(t_data *data, t_texture *t)
{
	t->img.img_ptr = mlx_xpm_file_to_image(data->mlx, t->path, &t->tex_w,
			&t->tex_h);
	if (!t->img.img_ptr)
		return (1);
	t->img.addr = mlx_get_data_addr(t->img.img_ptr, &t->img.bit_per_pixels,
			&t->img.line_lenght, &t->img.endian);
	if (!t->img.addr)
		return (1);
	t->img.bit_per_pixels /= 8;
	return (0);
}
