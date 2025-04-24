/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:30:10 by jle-doua          #+#    #+#             */
/*   Updated: 2025/04/24 13:26:33 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv, char **envp)
{
	t_data *data;

	if (!envp[0] || verif_args(argc, argv))
		return (1);
	data = init_data(argv[1]);
	if (data == NULL)
		return (1);
	print_texture_path(data->texture);
	print_map(data->map);
	mlx_loop(data->mlx);
	return (0);
}