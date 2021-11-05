#include "cub3d.h"

int	select_color(t_data *data, double tex_posy, char direct)
{
	int	tex_posx;

	if (direct == 'h')
	{
		tex_posx = ((int)(data->ray.x - ((int)(data->ray.x / SIZE) * SIZE))) / 2;
	} else if (direct == 'v')
	{
		tex_posx = ((int)(data->ray.y - ((int)(data->ray.y / SIZE) * SIZE))) / 2;
	}
	return (*(int *)(data->ray.texture.addr
	+ (int)tex_posy * data->ray.texture.ll
	+ tex_posx * (data->ray.texture.bpp / 8)));
}
