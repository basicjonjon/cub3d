/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:52:59 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/24 14:05:04 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_asset_path(t_asset *asset)
{
	printf("no wall %s%s%s", BGREEN, asset->no_path, NC);
	printf("so wall %s%s%s", BGREEN, asset->so_path, NC);
	printf("we wall %s%s%s", BGREEN, asset->we_path, NC);
	printf("ea wall %s%s%s", BGREEN, asset->ea_path, NC);
	printf("floor %s%i/%i/%i%s\n", BGREEN, asset->floor->r, asset->floor->g,
		asset->floor->b, NC);
	printf("ceiling %s%i/%i/%i%s\n", BGREEN, asset->ceiling->r,
		asset->ceiling->g, asset->ceiling->b, NC);
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
				printf("[%s%c%s]", BRED, map[i][y], NC);
			if (map[i][y] == '0')
				printf("[%s%c%s]", BGREEN, map[i][y], NC);
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
