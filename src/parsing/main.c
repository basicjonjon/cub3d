/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:30:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/22 13:05:32 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv, char **envp)
{
	t_texture *texture;
	char **map;

	if (!envp[0] || verif_args(argc, argv))
		return (1);
	texture = get_texture(argv[1]);
	print_texture_path(texture);
	map = get_map(argv[1]);
	print_map(map);
	return (0);
}