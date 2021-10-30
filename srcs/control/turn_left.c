#include "cub3d.h"

void	turn_left(t_data *data)
{
	if (data->player.angle >= dtr(0.0))
		data->player.angle -= dtr(ROT_SPEED);
	if (data->player.angle < dtr(0.0))
		data->player.angle = dtr(359.0);
}