/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:22 by jle-doua          #+#    #+#             */
/*   Updated: 2025/09/09 17:44:07 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		mlx_mouse_show(data->mlx, data->win);
		free_asset(data);
		if (data->param.map)
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
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
