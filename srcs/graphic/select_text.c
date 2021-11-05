/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:10:50 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 20:10:52 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_text(t_data *data)
{
	if ((int)(data->ray.prevy / SIZE) == (int)(data->ray.y / SIZE))
	{
		if ((int)(data->ray.prevx / SIZE) < (int)(data->ray.x / SIZE))
			data->ray.texture = data->textures.west;
		else
			data->ray.texture = data->textures.east;
	}
	else if ((int)(data->ray.prevx / SIZE) == (int)(data->ray.x / SIZE))
	{
		if ((int)(data->ray.prevy / SIZE) < (int)(data->ray.y / SIZE))
			data->ray.texture = data->textures.north;
		else
			data->ray.texture = data->textures.south;
	}
}
