/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:45:59 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/21 12:45:22 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_line_size(char *line)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (line[y] != '\0')
	{
		if (line[y] == 9)
			i += 4;
		else
			i++;
		y++;
	}
	return (i);
}

int	get_map_size_x(char *maps_file)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open(maps_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map(line))
		{
			if (count_line_size(line) > x)
				x = count_line_size(line);
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
	while (line && !is_map(line))
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
