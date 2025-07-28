/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:25 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/28 17:14:51 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*dup_map_line(char *line, int x)
{
	int		i;
	int		y;
	int		z;
	char	*res;

	i = 0;
	y = 0;
	res = malloc(sizeof(char) * x);
	if (!res)
		return (NULL);
	if (line[0] == '\n' || line[0] == '\0')
	{
		while (y < x - 1)
		{
			res[y++] = ' ';
		}
		res[y] = '\0';
		return (res);
	}
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
		else if (line[i] == '0' || line[i] == '1' || line[0] == 'P'
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W' || line[i] == ' ')
			res[y++] = line[i];
		i++;
	}
	while (y < x - 1)
	{
		res[y++] = ' ';
	}
	res[y] = '\0';
	return (res);
}
