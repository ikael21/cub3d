/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:18:48 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 20:18:50 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays(t_data *data)
{
	while (data->ray.number < W_WIDTH)
	{
		data->ray.distance = 0;
		while (++data->ray.distance < 2048)
		{
			calc_raypos(data);
			if (((int)data->ray.y / SIZE >= 0 && (int)data->ray.y
					/ SIZE < data->map.height) && ((int)data->ray.x / SIZE >= 0
					&& (int)data->ray.x / SIZE < data->map.width)
				&& data->map.map[(int)data->ray.y
					/ SIZE][(int)data->ray.x / SIZE] == '1')
			{
				put_texture(data);
				break ;
			}
			data->ray.prevx = data->ray.x;
			data->ray.prevy = data->ray.y;
		}
		data->ray.number++;
		data->ray.angle += dtr(data->delta_a);
	}
}
