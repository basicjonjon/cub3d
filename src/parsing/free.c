/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:22 by jle-doua          #+#    #+#             */
/*   Updated: 2025/06/02 14:13:55 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_asset(t_data *data)
{
	if (data->asset.no_path)
		free(data->asset.no_path);
	if (data->asset.so_path)
		free(data->asset.so_path);
	if (data->asset.ea_path)
		free(data->asset.ea_path);
	if (data->asset.we_path)
		free(data->asset.we_path);
	if (data->asset.floor)
		free(data->asset.floor);
	if (data->asset.ceiling)
		free(data->asset.ceiling);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->param.map[i])
	{
		free(data->param.map[i]);
		i++;
	}
	free(data->param.map);
}

void	free_all(t_data *data)
{
	if (data)
	{
		free_asset(data);
		free_map(data);
		if (data->img.img_ptr)
			mlx_destroy_image(data->mlx, data->img.img_ptr);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free(data);
		data = NULL;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}