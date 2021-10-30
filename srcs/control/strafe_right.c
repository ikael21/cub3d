#include "cub3d.h"

void	strafe_right(t_data *data)
{
	data->player.posx -= WALK_SPEED * sin(data->player.angle);
	data->player.posy += WALK_SPEED * cos(data->player.angle);
}