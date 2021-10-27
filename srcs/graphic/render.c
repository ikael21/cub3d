#include "cub3d.h"

void	printcube(t_data *data, int x, int y, char type)
{
	if (type == 'R')
	{
		int i = y * SIZE;
		while (i < y * SIZE + SIZE)
		{
			int j = x * SIZE;
			while (j < x * SIZE + SIZE)
			{
				pixel_put(data, j, i, 0xffffff);
				j++;
			}
			i++;
		}
	}
}

void	printmap(t_data *data)
{
	int i = 0;
	while (i < data->map.height)
	{
		int j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == '1')
				printcube(data, j, i, 'R');
			j++;
		}
		i++;
	}
}

void draw_player(t_data *data)
{
	int i = (int)data->player.posy - 2;
	while (i < (int)data->player.posy + 2)
	{
		int j = (int)data->player.posx - 2;
		while (j < (int)data->player.posx + 2)
		{
			pixel_put(data, j, i, 0x00ff0000);
			j++;
		}
		i++;
	}
	i = 2;
	while (i < 15)
	{
		pixel_put(data, (int)(data->player.posx + i * cos(data->player.angle * 3.14 / 180)), (int)(data->player.posy + i * sin(data->player.angle * 3.14 / 180)), 0x000000ff);
		i++;
	}
}

int	render(t_data *data)
{
	data->next.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->next.addr = mlx_get_data_addr(data->next.img, &data->next.bits_per_pixel, &data->next.line_length,
										&data->next.endian);
	move(data);
	printmap(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->next.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	data->img = data->next;
	usleep(8333);
	return (1);
}
