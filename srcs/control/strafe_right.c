#include "cub3d.h"

void	strafe_right(t_data *data)
{
	data->player.posx += (cos((data->player.angle + 90) * 3.14 / 180));
	data->player.posy += (sin((data->player.angle + 90) * 3.14 / 180));
	render(data);
}