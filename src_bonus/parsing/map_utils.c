/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:25 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/08 17:28:44 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dup_map_line(char *line, int x)
{
	int		i;
	int		y;
	int		z;
	char	*res;

	i = 0;
	y = 0;
	res = malloc(sizeof(char) * (x + 1));
	if (!res)
		return (NULL);
	while (line[i])
	{
		z = 0;
		if (line[i] == 9)
		{
			while (z < 4)
			{
				res[y++] = ' ';
				z++;
			}
		}
		else if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
			res[y++] = line[i];
		i++;
	}
	while (y != x)
	{
		res[y++] = ' ';
	}
	res[y] = '\0';
	return (res);
}
