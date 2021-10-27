#include "cub3d.h"

void	turn_right(t_data *data)
{
	if (data->player.angle < 360.0)
		data->player.angle += ROT_SPEED;
	if (data->player.angle > 359.0)
		data->player.angle = 0.0;
	render(data);
}