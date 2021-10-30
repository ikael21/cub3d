#include "cub3d.h"

void	walk_forward(t_data *data)
{
	data->player.posx += WALK_SPEED * cos(data->player.angle);
	data->player.posy += WALK_SPEED * sin(data->player.angle);
}