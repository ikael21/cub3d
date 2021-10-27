#include "cub3d.h"

void	walk_backward(t_data *data)
{
	data->player.posx += (cos((data->player.angle + 180) * 3.14 / 180));
	data->player.posy += (sin((data->player.angle + 180) * 3.14 / 180));
}