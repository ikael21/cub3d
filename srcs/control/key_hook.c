#include "cub3d.h"

int key_hook(int keycode, void *params)
{
	t_data *data;

	data = (t_data *)params;
	if (keycode == W)
		walk_forward(data);
	if (keycode == A)
		strafe_left(data);
	if (keycode == S)
		walk_backward(data);
	if (keycode == D)
		strafe_right(data);
	if (keycode == LEFT)
		turn_left(data);
	if (keycode == RIGHT)
		turn_right(data);
	if (keycode == ESC)
		close_game();

	return (1);
}