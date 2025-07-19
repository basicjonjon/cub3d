/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:38:01 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/19 14:11:29 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_init(t_data *data, t_asset *a)
{
	if (create_img(data, &a->north))
		return (ft_fprintf(2, "%sERROR : image creation failed\n%s", BRED, NC),
			1);
	if (create_img(data, &a->south))
		return (ft_fprintf(2, "%sERROR : image creation failed\n%s", BRED, NC),
			1);
	if (create_img(data, &a->east))
		return (ft_fprintf(2, "%sERROR : image creation failed\n%s", BRED, NC),
			1);
	if (create_img(data, &a->west))
		return (ft_fprintf(2, "%sERROR : image creation failed\n%s", BRED, NC),
			1);
	return (0);
}
