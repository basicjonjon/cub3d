/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:30:46 by jle-doua          #+#    #+#             */
/*   Updated: 2025/09/09 15:46:34 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	is_map(char *line)
{
	if ((line[0] == ' ' || line[0] == '0' || line[0] == '1' || line[0] == 1
			|| line[0] == 9))
	{
		return (1);
	}
	return (0);
}