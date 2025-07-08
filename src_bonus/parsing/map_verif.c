/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:04:31 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/08 17:22:15 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_floor(char **map, int x, int y)
{
	if ((x != 0 && map[y][x - 1] == ' ') || x == 0)
	{
		return (1);
	}
	if (map[y][x + 1] == '\0' || map[y][x + 1] == ' ')
	{
		return (1);
	}
	if ((y != 0 && map[y - 1][x] == ' ') || y == 0)
	{
		return (1);
	}
	if ((map[y + 1] != NULL && map[y + 1][x] == ' ') || map[y + 1] == NULL)
	{
		return (1);
	}
	return (0);
}

int	verif_floor_diag(char **map, int x, int y)
{
	if (map[y - 1][x - 1] == ' ')
	{
		return (1);
	}
	if (map[y + 1][x - 1] == ' ')
	{
		return (1);
	}
	if (map[y - 1][x + 1] == ' ')
	{
		return (1);
	}
	if (map[y + 1][x + 1] == ' ')
	{
		return (1);
	}
	return (0);
}

int	verif_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->param.map[y])
	{
		x = 0;
		while (data->param.map[y][x])
		{
			if (data->param.map[y][x] == '0')
			{
				if (verif_floor(data->param.map, x, y)
					|| verif_floor_diag(data->param.map, x, y))
				{
					printf("%sERROR: map is invalide%s\n", BRED, NC);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_map_player(t_data *data)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = 0;
	while (data->param.map[y])
	{
		x = 0;
		while (data->param.map[y][x])
		{
			if (data->param.map[y][x] == 'N' || data->param.map[y][x] == 'S'
				|| data->param.map[y][x] == 'W' || data->param.map[y][x] == 'E')
				player++;
			x++;
		}
		y++;
	}
	if (player != 1)
	{
		printf("%sERROR: player is invalide%s\n", BRED, NC);
		return (1);
	}
	return (0);
}
