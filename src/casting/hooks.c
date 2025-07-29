/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:09:19 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/29 13:40:00 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.keyup = false;
	if (keysym == XK_s)
		data->player.keydown = false;
	if (keysym == XK_a)
		data->player.keyleft = false;
	if (keysym == XK_d)
		data->player.keyright = false;
	if (keysym == XK_Left)
		data->player.rotleft = false;
	if (keysym == XK_Right)
		data->player.rotright = false;
	if (keysym == XK_Shift_L)
		data->player.run = false;
	return (keysym);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.keyup = true;
	if (keysym == XK_s)
		data->player.keydown = true;
	if (keysym == XK_a)
		data->player.keyleft = true;
	if (keysym == XK_d)
		data->player.keyright = true;
	if (keysym == XK_Left)
		data->player.rotleft = true;
	if (keysym == XK_Right)
		data->player.rotright = true;
	if (keysym == XK_Shift_L)
		data->player.run = true;
	if (keysym == XK_Escape)
		close_win(data);
	return (keysym);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_win, data);
}
