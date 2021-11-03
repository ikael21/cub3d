#include "cub3d.h"

void	put_line(t_data *data)
{
	int	height;
	int	start;
	int end;

	data->ray.distance *= cos(data->player.angle - data->ray.angle);
	height = (int)((double)FOCUS * SIZE / data->ray.distance);
	start = (W_HEIGHT - height) / 2;
	end = start + height;
	while (start < end)
	{
		if (start >= 0 && start < W_HEIGHT && data->ray.number > 0 && data->ray.number < W_WIDTH)
			pixel_put(data, data->ray.number, start, 0x000000ff);
		start++;
	}
}

void	select_text(t_data *data)
{
	if ((int)data->ray.x % SIZE < SIZE && (int)data->ray.y % SIZE > SIZE)
	{
		if ((int)(data->player.posx / SIZE) < (int)data->ray.x)
			data->ray.texture = data->textures.west;
		else if ((int)(data->player.posx / SIZE) > (int)data->ray.x)
			data->ray.texture = data->textures.east;
	}
	else if ((int)data->ray.y % SIZE < SIZE && (int)data->ray.x % SIZE < SIZE)
	{
		if ((int)(data->player.posy / SIZE) < (int)data->ray.y)
			data->ray.texture = data->textures.south;
		else if ((int)(data->player.posy / SIZE) > (int)data->ray.y)
			data->ray.texture = data->textures.north;
	}
}

void	put_texture(t_data *data)
{
	double tex_pos;

	data->ray.distance *= cos(data->player.angle - data->ray.angle);
	data->ray.height = (int)((double)FOCUS * SIZE / data->ray.distance);
	data->ray.scale = 64 / (double)data->ray.height;
	data->ray.start = (W_HEIGHT - data->ray.height) / 2;
	data->ray.end = data->ray.start + data->ray.height;
	tex_pos = 0;
//	select_text(data);
	data->ray.texture = data->textures.east;
	while (data->ray.start < data->ray.end)
	{
		if (data->ray.start >= 0 && data->ray.start < W_HEIGHT && data->ray.number > 0 && data->ray.number < W_WIDTH)
		{
			pixel_put(data, data->ray.number, data->ray.start, *(int *)(data->ray.texture.addr + (int)tex_pos * (data->ray.texture.bpp / 8)));
		}
		tex_pos+=data->ray.scale;
		data->ray.start++;
	}
}

void	raycasting(t_data *data)
{

	data->ray.angle = data->player.angle - dtr(H_FOW);
	data->ray.number = 0;
	while (data->ray.angle < data->player.angle + dtr(H_FOW))
	{
		data->ray.distance = 0;
		while (++data->ray.distance < 2048)
		{
			data->ray.x = data->player.posx + data->ray.distance * cos(data->ray.angle);
			data->ray.y = data->player.posy + data->ray.distance * sin(data->ray.angle);
			if (((int)data->ray.y / SIZE >= 0 && (int)data->ray.y / SIZE < data->map.height) && ((int)data->ray.x / SIZE >= 0 && (int)data->ray.x / SIZE < data->map.width) && data->map.map[(int)data->ray.y / SIZE][(int)data->ray.x 	/ SIZE] == '1')
			{
//				put_line(data);
				put_texture(data);
				break;
			}
		}
		data->ray.number++;
		data->ray.angle += dtr(DELTA_A);
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

void kek(t_data *data)
{
	int i;
	int j;
	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			pixel_put(data, i + 10, j + 10, *(int *)(data->textures.south.addr + i * data->textures.south.ll + j * (data->textures.south.bpp / 8)));
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	data->next.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->next.addr = mlx_get_data_addr(data->next.img, &data->next.bits_per_pixel, &data->next.line_length,
										&data->next.endian);
	move(data);
	drawing(data);
//	kek(data);
	mlx_put_image_to_window(data->mlx, data->win, data->next.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	data->img = data->next;
	usleep(16666);
	return (1);
}
