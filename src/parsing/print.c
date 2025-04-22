/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:52:59 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/22 14:17:14 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_texture_path(t_texture *texture)
{
	printf("no wall %s%s%s", BGREEN, texture->no_path, NC);
	printf("so wall %s%s%s", BGREEN, texture->so_path, NC);
	printf("we wall %s%s%s", BGREEN, texture->we_path, NC);
	printf("ea wall %s%s%s", BGREEN, texture->ea_path, NC);
	printf("floor %s%i/%i/%i%s\n", BGREEN, texture->floor->r, texture->floor->g,
		texture->floor->b, NC);
	printf("ceiling %s%i/%i/%i%s\n", BGREEN, texture->ceiling->r,
		texture->ceiling->g, texture->ceiling->b, NC);
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
			{
				printf("[");
				printf("%s%c%s", BRED, map[i][y], NC);
				printf("]");
			}
			if (map[i][y] == '0')
			{
				printf("[");
				printf("%s%c%s", BGREEN, map[i][y], NC);
				printf("]");
			}
			if (map[i][y] == ' ')
			{
				printf("[ ]");
			}
			y++;
		}
		printf("\n");
		i++;
	}
}
