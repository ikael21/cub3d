/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:14:05 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 20:14:08 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	data->ray.angle = data->player.angle - dtr(data->h_fow);
	data->ray.number = 0;
	data->ray.prevx = 0;
	data->ray.prevy = 0;
	rays(data);
}

void	drawing(t_data *data)
{
	draw_floor_and_cell(data);
	raycasting(data);
}

int	render(t_data *data)
{
	data->next.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->next.addr = mlx_get_data_addr(data->next.img,
			&data->next.bits_per_pixel, &data->next.line_length,
			&data->next.endian);
	move(data);
	drawing(data);
	mlx_put_image_to_window(data->mlx, data->win, data->next.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	data->img = data->next;
	usleep(16666);
	return (1);
}
