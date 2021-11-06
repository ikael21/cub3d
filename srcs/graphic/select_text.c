/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikael <ikael@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:10:50 by lvallie           #+#    #+#             */
/*   Updated: 2021/11/05 22:52:55 by ikael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_text(t_data *data, char *direct)
{
	if ((int)(data->ray.prevy / SIZE) == (int)(data->ray.y / SIZE))
	{
		if ((int)(data->ray.prevx / SIZE) < (int)(data->ray.x / SIZE))
			data->ray.texture = data->textures.east;
		else
			data->ray.texture = data->textures.west;
		*direct = 'v';
	}
	else if ((int)(data->ray.prevx / SIZE) == (int)(data->ray.x / SIZE))
	{
		if ((int)(data->ray.prevy / SIZE) < (int)(data->ray.y / SIZE))
			data->ray.texture = data->textures.south;
		else
			data->ray.texture = data->textures.north;
		*direct = 'h';
	}
}
