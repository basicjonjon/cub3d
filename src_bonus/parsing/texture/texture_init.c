/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:38:01 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/28 17:36:13 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	texture_init(t_data *data, t_asset *a)
{
	if (create_img(data, &a->north))
		return (ft_fprintf(2, "%sERROR: north creation failed\n%s", BRED, NC),
			1);
	if (create_img(data, &a->south))
		return (ft_fprintf(2, "%sERROR: south creation failed\n%s", BRED, NC),
			1);
	if (create_img(data, &a->east))
		return (ft_fprintf(2, "%sERROR: east creation failed\n%s", BRED, NC),
			1);
	if (create_img(data, &a->west))
		return (ft_fprintf(2, "%sERROR: west creation failed\n%s", BRED, NC),
			1);
	data->asset.door.path = DOOR;
	if (create_img(data, &a->door))
		return (ft_fprintf(2, "%sERROR: door creation failed\n%s", BRED, NC),
			1);
	return (0);
}
