/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:45:59 by jle-doua          #+#    #+#             */
/*   Updated: 2025/07/19 13:51:39 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	count_blank_line(int fd)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		if (is_map(line))
			return (free(line), i);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

char	*skip_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (!is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int	get_map_size_y(char *maps_file)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(maps_file, O_RDONLY);
	line = skip_line(fd);
	while (line != NULL)
	{
		if (is_map(line))
			y++;
		if (line[0] == '\n')
			y += count_blank_line(fd);
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), y);
}
