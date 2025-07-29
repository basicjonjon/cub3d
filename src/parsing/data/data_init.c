/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:49:28 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/29 13:18:04 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_fprintf(2, "Error: mlx malloc"), free_all(data), 1);
	data->win = mlx_new_window(data->mlx, screenWidth, screenHeight, "Cub3d");
	if (!data->win)
		return (ft_fprintf(2, "Error: window malloc"), free_all(data), 1);
	data->img.img_ptr = mlx_new_image(data->mlx, screenWidth, screenHeight);
	if (!data->img.img_ptr)
		return (ft_fprintf(2, "Error: img malloc"), free_all(data), 1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bit_per_pixels, &data->img.line_lenght,
			&data->img.endian);
	if (!data->img.addr)
		return (ft_fprintf(2, "Error: img addr malloc"), free_all(data), 1);
	data->img.bit_per_pixels /= 8;
	return (0);
}

void	init_config(t_config *conf, t_map *map)
{
	conf->mapW = map->mapX;
	conf->mapH = map->mapY;
	conf->fov = M_PI / 3;
	conf->move_speed = 0.008;
	conf->run_speed = conf->move_speed * 3;
	conf->rot_speed = 0.02;
	conf->nbr_rays = screenWidth;
	conf->column_width = 1;
}

int	init_data(t_data *data, char *map_file)
{
	ft_memset(data, 0, sizeof(t_data));
	data->param.map = NULL;
	if (init_mlx(data) == 1)
		return (1);
	if (get_asset(map_file, data))
		return (free_all(data), 1);
	if (texture_init(data, &data->asset))
		return (free_all(data), 1);
	if (get_map(data, map_file))
		return (free_all(data), 1);
	if (verif_map(data) || verif_map_player(data))
		return (free_all(data), 1);
	init_config(&data->conf, &data->param);
	init_player(data);
	ft_memset(&data->hit, 0, sizeof(t_hit));
	return (0);
}
