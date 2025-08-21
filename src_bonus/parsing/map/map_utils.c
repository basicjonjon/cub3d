/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:25 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/21 11:49:07 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_map_char(char map_char)
{
	if (map_char == '0' || map_char == '1' || map_char == 'P' || map_char == 'N'
		|| map_char == 'S' || map_char == 'E' || map_char == 'W'
		|| map_char == ' ')
	{
		return (1);
	}
	return (0);
}

char	*dup_empty_line(int x, char *res)
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

int	dup_tab(char *res, int y)
{
	int	z;

	z = 0;
	while (z < 4)
	{
		res[y++] = ' ';
		z++;
	}
	return (y);
}

char	*dup_map_line(char *line, int x)
{
	int		i;
	int		y;
	char	*res;

	i = 0;
	y = 0;
	res = malloc(sizeof(char) * x);
	if (!res)
		return (NULL);
	if (line[0] == '\n' || line[0] == '\0')
		dup_empty_line(x, res);
	while (line[i])
	{
		if (line[i] == 9)
			y = dup_tab(res, y);
		else if (is_map_char(line[i]))
			res[y++] = line[i];
		i++;
	}
	while (y < x - 1)
		res[y++] = ' ';
	res[y] = '\0';
	return (res);
}
