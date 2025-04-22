/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:25 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/22 16:05:56 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	while (i != x)
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
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			res[y++] = line[i];
		else
			res[y++] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}
