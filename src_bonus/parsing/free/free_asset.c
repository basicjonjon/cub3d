
#include "cub3d_bonus.h"

void	free_texture(t_data *data, t_texture *texture)
{
	if (texture->path)
		free(texture->path);
	if (texture->img.img_ptr)
		mlx_destroy_image(data->mlx, texture->img.img_ptr);
}

void	free_texture_nopath(t_data *data, t_texture *texture)
{
	if (texture->img.img_ptr)
		mlx_destroy_image(data->mlx, texture->img.img_ptr);
}

void	free_hud_texture(t_data *data, t_texture texture[], int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free_texture_nopath(data, &texture[i]);
		i++;
	}
}

void	free_asset(t_data *data)
{
	free_texture(data, &data->asset.north);
	free_texture(data, &data->asset.south);
	free_texture(data, &data->asset.west);
	free_texture(data, &data->asset.east);
	free_texture_nopath(data, &data->asset.tceiling);
	free_texture_nopath(data, &data->asset.tfloor);
	free_texture_nopath(data, &data->asset.door);
	free_hud_texture(data, data->hud.batterie, 6);
	free_hud_texture(data, data->hud.rec, 2);
	free_hud_texture(data, data->hud.border, 4);
	free_texture_nopath(data, &data->hud.center_cam);
}
