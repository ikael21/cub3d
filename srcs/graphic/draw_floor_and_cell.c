/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_cell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:02:05 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 20:02:10 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_and_cell(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < W_HEIGHT / 2)
	{
		j = -1;
		while (++j < W_WIDTH)
			pixel_put(data, j, i, data->map.c_color);
	}
	i = W_HEIGHT / 2 - 1;
	while (++i < W_HEIGHT)
	{
		j = -1;
		while (++j < W_WIDTH)
			pixel_put(data, j, i, data->map.f_color);
	}
}
