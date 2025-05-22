/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:49:28 by jle-doua          #+#    #+#             */
/*   Updated: 2025/05/22 17:43:56 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data_null(t_data *data)
{
	data->map = NULL;
	data->mlx = NULL;
	data->texture = NULL;
	data->win = NULL;
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_fprintf(2, "Error: mlx malloc"), free_all(data), 1);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Cub3d");
	if (!data->win)
		return (ft_fprintf(2, "Error: window malloc"), free_all(data), 1);
	data->img.img_ptr = mlx_new_image(data->mlx, screenWidth, screenHeight);
	if (!data->img.img_ptr)
		return (ft_fprintf(2, "Error: img malloc"), free_all(data), 1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
									&data->img.bit_per_pixels,
									&data->img.line_lenght,
									&data->img.endian);
	if (!data->img.addr)
		return (ft_fprintf(2, "Error: img addr malloc"), free_all(data), 1);
	data->img.bit_per_pixels /= 8;
	return (0);
}

t_data	*init_data(char *map_file)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_data_null(data);
	if (init_mlx(data) == 1)
		return (NULL);
	data->asset = get_asset(map_file);
	if (!data->asset)
		return (free_all(data), NULL);
	data->map = get_map(map_file);
	if (!data->map)
		return (free_all(data), NULL);
	data->texture = init_texture(data);
	if (data->texture == NULL || verif_texture(data))
		return (free_all(data), NULL);
	if (verif_map(data))
		return (free_all(data), NULL);
	return (data);
}
