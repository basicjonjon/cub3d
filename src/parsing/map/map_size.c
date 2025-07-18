/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:45:59 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/18 17:04:47 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	get_separated_map(int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (is_map(line))
// 	{
// 		/* code */
// 	}
// 	return (i);
// }

int	get_map_size_x(char *maps_file)
{
	int		i;
	int		y;
	int		fd;
	int		x;
	char	*line;

	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	while (line != NULL)
	{
		i = 0;
		if (is_map(line))
		{
			y = 0;
			while (line[y] != '\0')
			{
				if (line[y] == 9)
					i += 4;
				else
					i++;
				y++;
			}
			if (i > x)
				x = i;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), x);
}

int	get_map_size_y(char *maps_file)
{
	int		y;
	int		i;
	int		fd;
	char	*line;

	y = 0;
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map(line))
			y++;
		if (line[0] == '\n')
		{
			i = 0;
			while (line != NULL)
			{
				i++;
				if (is_map(line))
				{
					y += i;
					break ;
				}
				free(line);
				line = get_next_line(fd);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), y);
}
