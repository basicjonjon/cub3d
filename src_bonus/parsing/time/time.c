/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:11:43 by jle-doua          #+#    #+#             */
/*   Updated: 2025/08/20 15:19:39 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
