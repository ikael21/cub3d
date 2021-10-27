#include "cub3d.h"

void	strafe_left(t_data *data)
{
	data->player.posx += (cos((data->player.angle + 270) * 3.14 / 180));
	data->player.posy += (sin((data->player.angle + 270) * 3.14 / 180));
	render(data);
}