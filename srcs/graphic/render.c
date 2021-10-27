#include "cub3d.h"

void	put_line(t_data *data, int j, double i, double angle)
{
	double	height;
	double	start;
	double	k;

	height = (W_HEIGHT - (double)i * SCALE);
	start = (W_HEIGHT - height) / 2;
	k = start;
	while (k < start + height)
	{
		pixel_put(data, j, (int)k, 0x000000ff);
		k++;
	}
}

void drawing(t_data *data)
{
	double	x;
	double	y;
	double 	i;
	double	angle;
	int		j;

	j = 0;
	while (j < W_WIDTH)
	{
		i = 2;
		while (i < 256)
		{
			angle = (double)j * ANGLE - 45;
			x = data->player.posx + i * cos((data->player.angle + angle) * 3.14 / 180);
			y = data->player.posy + i * sin((data->player.angle + angle) * 3.14 / 180);
//			pixel_put(data, (int)x, (int)y, 0x00000099);
			if (data->map.map[(int)y / SIZE][(int)x / SIZE] == '1')
			{
				put_line(data, j, i, angle);
				break;
			}
			i+=1.0;
		}
		j++;
	}
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
