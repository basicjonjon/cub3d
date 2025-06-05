/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:49:28 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/05 17:07:52 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	init_data_null(t_data *data)
// {
// 	data->mlx = NULL;
// 	data->win = NULL;
// }

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

void	init_config(t_config *conf)
{
	conf->block = 64;
	conf->player_size = 10;
	conf->mapX = 0;
	conf->mapY = 0;
	conf->fov = 0.0;
	conf->move_speed = 0.5;
	conf->rot_speed = 0.1;
}

t_data	*init_data(char *map_file)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset(data, 0, sizeof(t_data));
	if (init_mlx(data) == 1)
		return (NULL);
	if (get_asset(map_file, data))
		return (free_all(data), NULL);
	if (get_map(data, map_file))
		return (free_all(data), NULL);
	if (verif_map(data) || verif_map_player(data))
		return (free_all(data), NULL);
	init_config(&data->conf);
	init_player(data);
	return (data);
}
