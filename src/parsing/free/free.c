/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:22 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/19 14:18:43 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_asset(t_data *data)
{
	if (data->asset.north.path)
		free(data->asset.north.path);
	if (data->asset.south.path)
		free(data->asset.south.path);
	if (data->asset.east.path)
		free(data->asset.east.path);
	if (data->asset.west.path)
		free(data->asset.west.path);
	if (data->asset.north.img.img_ptr)
		mlx_destroy_image(data->mlx, data->asset.north.img.img_ptr);
	if (data->asset.south.img.img_ptr)
		mlx_destroy_image(data->mlx, data->asset.south.img.img_ptr);
	if (data->asset.west.img.img_ptr)
		mlx_destroy_image(data->mlx, data->asset.west.img.img_ptr);
	if (data->asset.east.img.img_ptr)
		mlx_destroy_image(data->mlx, data->asset.east.img.img_ptr);
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