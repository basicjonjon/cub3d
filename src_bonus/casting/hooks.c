/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:09:19 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/07/22 14:35:49 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	close_win(t_data *data)
{
	// mlx_destroy_image(data->mlx, data->img.img_ptr);
	// mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_display(data->mlx);
	// free(data->mlx);
	// free(data);
	// data = NULL;
	free_all(data);
	exit(EXIT_SUCCESS);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.keyUp = false;
	if (keysym == XK_s)
		data->player.keyDown = false;
	if (keysym == XK_a)
		data->player.keyLeft = false;
	if (keysym == XK_d)
		data->player.keyRight = false;
	if (keysym == XK_Left)
		data->player.rotLeft = false;
	if (keysym == XK_Right)
		data->player.rotRight = false;
	if (keysym == XK_Shift_L)
		data->player.run = false;
	return (keysym);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.keyUp = true;
	if (keysym == XK_s)
		data->player.keyDown = true;
	if (keysym == XK_a)
		data->player.keyLeft = true;
	if (keysym == XK_d)
		data->player.keyRight = true;
	if (keysym == XK_Left)
		data->player.rotLeft = true;
	if (keysym == XK_Right)
		data->player.rotRight = true;
	if (keysym == XK_m && data->player.map == false)
		data->player.map = true;
	else if (keysym == XK_m && data->player.map == true)
		data->player.map = false;
	if (keysym == XK_Shift_L)
		data->player.run = true;
	if (keysym == XK_Escape)
		close_win(data);
	if (keysym == XK_p)
		printf("posX = %f ; posY = %f ; angle = %f\n\n", data->player.x,
			data->player.y, data->player.angle);
	return (keysym);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_win, data);
	// mlx_loop_hook(data->mlx, move_loop, data);
}
