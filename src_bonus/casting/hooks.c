/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarps <mmarps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:09:19 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/08/21 00:18:55 by mmarps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	close_win(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.key_up = false;
	if (keysym == XK_s)
		data->player.key_down = false;
	if (keysym == XK_a)
		data->player.key_left = false;
	if (keysym == XK_d)
		data->player.key_right = false;
	if (keysym == XK_Left)
		data->player.rot_left = false;
	if (keysym == XK_Right)
		data->player.rot_right = false;
	if (keysym == XK_Shift_L)
		data->player.run = false;
	if (keysym == XK_e)
		data->player.interact = false;
	return (keysym);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.key_up = true;
	if (keysym == XK_s)
		data->player.key_down = true;
	if (keysym == XK_a)
		data->player.key_left = true;
	if (keysym == XK_d)
		data->player.key_right = true;
	if (keysym == XK_Left)
		data->player.rot_left = true;
	if (keysym == XK_Right)
		data->player.rot_right = true;
	if (keysym == XK_space && data->player.map == false)
		data->player.map = true;
	else if (keysym == XK_space && data->player.map == true)
		data->player.map = false;
	if (keysym == XK_Shift_L)
		data->player.run = true;
	if (keysym == XK_Escape)
		close_win(data);
	if (keysym == XK_e)
		data->player.interact = true;
	return (keysym);
}

void	hooks(t_data *data)
{
	mlx_mouse_hide(data->mlx, data->win);
	mlx_mouse_move(data->mlx, data->win, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_win, data);
}
