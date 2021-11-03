#include "cub3d.h"

void	put_line(t_data *data, int line, double distance, double angle)
{
	int	height;
	int	start;
	int end;

	distance *= cos(data->player.angle - angle);
	height = (int)((double)FOCUS * SIZE / distance);
	start = (W_HEIGHT - height) / 2;
	end = start + height;
	while (start < end)
	{
		if (start >= 0 && start < W_HEIGHT && line > 0 && line < W_WIDTH)
			pixel_put(data, line, start, 0x000000ff);
		start++;
	}
}

void	raycasting(t_data *data)
{
	double	i;
	double	x;
	double	y;
	double	j;
	int		k;

	i = data->player.angle - dtr(H_FOW);
	k = 0;
	while (i < data->player.angle + dtr(H_FOW))
	{
		j = 1;
		while (j < 1024)
		{
			x = data->player.posx + j * cos(i);
			y = data->player.posy + j * sin(i);
			if (((int)y / SIZE >= 0 && (int)y / SIZE < data->map.height) && ((int)x / SIZE >= 0 && (int)x / SIZE < data->map.width) && data->map.map[(int)y / SIZE][(int)x / SIZE] == '1')
			{
				put_line(data, k, j, i);
				break;
			}
			j+=1.0;
		}
		k++;
		i+=dtr(DELTA_A);
	}
}

void draw_floor_and_cell(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < W_HEIGHT/2)
	{
		j = -1;
		while (++j < W_WIDTH)
			pixel_put(data, j, i, data->map.c_color);
	}
	i = W_HEIGHT/2 - 1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
			pixel_put(data, j, i, data->map.f_color);
	}
}

void drawing(t_data *data)
{
	draw_floor_and_cell(data);
	raycasting(data);
}

int	render(t_data *data)
{
	data->next.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->next.addr = mlx_get_data_addr(data->next.img, &data->next.bits_per_pixel, &data->next.line_length,
										&data->next.endian);
	move(data);
	drawing(data);
	mlx_put_image_to_window(data->mlx, data->win, data->next.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	data->img = data->next;
	usleep(8333);
	return (1);
}
