#include "cub3d.h"

void	turn_left(t_data *data)
{
	if (data->player.angle >= 0.0)
		data->player.angle -= ROT_SPEED;
	if (data->player.angle < 0.0)
		data->player.angle = 359.0;
	render(data);
}