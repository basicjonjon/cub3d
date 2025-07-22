/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:52:59 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/18 14:25:26 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_asset_path(t_asset asset)
{
	printf("no wall %s%s%s\n", BGREEN, asset.north.path, NC);
	printf("so wall %s%s%s\n", BGREEN, asset.south.path, NC);
	printf("we wall %s%s%s\n", BGREEN, asset.east.path, NC);
	printf("ea wall %s%s%s\n", BGREEN, asset.west.path, NC);
	// printf("floor %s%i/%i/%i%s\n", BGREEN, asset.floor->r, asset.floor->g,
	// 	asset.floor->b, NC);
	// printf("ceiling %s%i/%i/%i%s\n", BGREEN, asset.ceiling->r, asset.ceiling->g,
	// 	asset.ceiling->b, NC);
	printf("floor %s%x%s\n", BGREEN, asset.floor, NC);
	printf("ceiling %s%x%s\n", BGREEN, asset.ceiling, NC);
}

void	print_player_info(t_data *data)
{
	printf("player x %s%f%s\n", BGREEN, data->player.x, NC);
	printf("player y %s%f%s\n", BGREEN, data->player.y, NC);
	printf("player angle %s%.2f%s\n", BGREEN, data->player.angle, NC);
}

void	print_map_info(t_data *data)
{
	printf("map x %s%i%s\n", BGREEN, data->param.mapX, NC);
	printf("map Y %s%i%s\n", BGREEN, data->param.mapY, NC);
}

void	print_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i] != NULL)
	{
		y = 0;
		while (map[i][y] != '\0')
		{
			if (map[i][y] == '1')
				printf("[%s%c%s]", BYELLOW, map[i][y], NC);
			if (map[i][y] == '0')
				printf("[%s%c%s]", BLACK, map[i][y], NC);
			if (map[i][y] == ' ')
				printf("[ ]");
			if (map[i][y] == 'N' || map[i][y] == 'S' || map[i][y] == 'E'
				|| map[i][y] == 'W')
				printf("[%s%c%s]", BBLUE, map[i][y], NC);
			y++;
		}
		printf("\n");
		i++;
	}
}
