/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:31:27 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/06/05 17:46:06 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x > screenWidth || y > screenHeight || x < 0 || y < 0)
		return ;
	offset = (y * img->line_lenght) + (x * (img->bit_per_pixels));
	*(unsigned int *)(img->addr + offset) = color;
}

int verif_move(t_player *player)
{
	if (player->keyDown || player->keyLeft
		|| player->keyRight || player->keyUp
		|| player->rotLeft || player->rotRight)
		return (1);
	else
		return (0);
}

int	check_colision(float x, float y, char **map)
{
	// int	i = ((x + playerSize / 2) + 1) / BLOCK;
	// int	j = ((y + playerSize / 2) + 1) / BLOCK;
	int	i;
	int	j;

	i = x / BLOCK;
	j = y / BLOCK;
	if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight)
		return (0);
	if (map[j][i] && map[j][i] == '1')
		return (0);
	return (1);
}
