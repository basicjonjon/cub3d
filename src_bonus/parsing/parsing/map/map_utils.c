/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:25 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/22 14:10:45 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dup_blank_line(char *res, int x)
{
	int	y;

	y = 0;
	while (y < x - 1)
	{
		res[y++] = ' ';
	}
	res[y] = '\0';
	return (res);
}

char	*complet_line(int y, int x, char *res)
{
	while (y < x - 1)
	{
		res[y++] = ' ';
	}
	res[y] = '\0';
	return (res);
}

char	*dup_normal_line(char *line, char *res, int x)
{
	int	i;
	int	z;
	int	y;

	i = 0;
	y = 0;
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
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == ' ')
			res[y++] = line[i];
		i++;
	}
	return (complet_line(y, x, res));
}

char	*dup_map_line(char *line, int x)
{
	char	*res;

	res = malloc(sizeof(char) * x);
	if (!res)
		return (NULL);
	if (line[0] == '\n' || line[0] == '\0')
		return (dup_blank_line(res, x));
	dup_normal_line(line, res, x);
	return (res);
}
