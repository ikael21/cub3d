#include "cub3d.h"

int key_hook_press(int keycode, void *params)
{
	t_data *data;

	data = (t_data *)params;
	if (keycode == W)
		data->player.keys.w = 1;
	if (keycode == A)
		data->player.keys.a = 1;
	if (keycode == S)
		data->player.keys.s = 1;
	if (keycode == D)
		data->player.keys.d = 1;
	if (keycode == LEFT)
		data->player.keys.left = 1;
	if (keycode == RIGHT)
		data->player.keys.right = 1;
	if (keycode == ESC)
		close_game();

	return (1);
}

int key_hook_release(int keycode, void *params)
{
	t_data *data;

	data = (t_data *)params;
	if (keycode == W)
		data->player.keys.w = 0;
	if (keycode == A)
		data->player.keys.a = 0;
	if (keycode == S)
		data->player.keys.s = 0;
	if (keycode == D)
		data->player.keys.d = 0;
	if (keycode == LEFT)
		data->player.keys.left = 0;
	if (keycode == RIGHT)
		data->player.keys.right = 0;
	if (keycode == ESC)
		close_game();

	return (1);
}